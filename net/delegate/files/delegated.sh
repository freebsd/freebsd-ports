#!/bin/sh

umask 027
if [ -x /usr/local/sbin/delegated ]; then
        echo -n ' delegated'
	/usr/local/sbin/delegated -P8080 -Txt \
	ADMIN=delegate-master@your.host.domain \
        CHARCODE=JIS \
        CACHEDIR=/var/spool/delegate/cache \
        EXPIRE=7d \
        RELIABLE=hostname \
        > /dev/null 2>&1
fi
