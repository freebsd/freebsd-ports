#!/bin/sh

if [ -f __PRERFIX__/etc/adzapper.conf ]; then
	__PREFIX__/sbin/adzapper &
	test $? -eq 0 && echo -n ' adzapper'
fi
