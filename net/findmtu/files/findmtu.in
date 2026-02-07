#!/bin/sh
if netstat -rn -f inet6 | grep -qv $1; then
	# Delete host route. As it is not in the routing table,
	# we are sure that it is a cloned route and can be deleted
	# safely
	route delete -inet6 $i > /dev/null 2> /dev/null
fi
%%PREFIX%%/bin/findmtu.real $1
