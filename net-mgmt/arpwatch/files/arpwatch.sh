#!/bin/sh
if [ -x /usr/local/sbin/arpwatch -a -d /usr/local/arpwatch ]; then
	arpwatch && echo -n ' arpwatch'
fi
