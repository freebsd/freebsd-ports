#!/bin/sh

# start dnews if it's really there ... usually in /usr/local ...

[ -x /usr/local/lib/dnews/dnews_start ] \
	&& /usr/local/lib/dnews/dnews_start > /dev/null 2>&1 &

# dnews started successfully if exit status = 0

if [ $? -eq 0 ]; then
	echo -n ' dnews'
fi
