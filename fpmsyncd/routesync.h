#ifndef __ROUTESYNC__
#define __ROUTESYNC__

#include "dbconnector.h"
#include "producertable.h"
#include "netmsg.h"

namespace swss {

class RouteSync : public NetMsg
{
public:
    enum { MAX_ADDR_SIZE = 64 };

    RouteSync(DBConnector *db);

    virtual void onMsg(int nlmsg_type, struct nl_object *obj);

private:
    ProducerTable m_routeTable;
    struct nl_cache *m_link_cache;
    struct nl_sock *m_nl_sock;
};

}

#endif
