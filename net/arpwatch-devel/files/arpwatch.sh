#!/bin/sh
if [ -x /usr/local/sbin/arpwatch -a -d /usr/local/arpwatch ]; then
	/usr/local/sbin/arpwatch && echo -n ' arpwatch'
fi
