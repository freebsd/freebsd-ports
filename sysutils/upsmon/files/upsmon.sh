#!/bin/sh

# see !!PREFIX!!/share/doc/upsmon/INSTALL for command line option details

if [ -x !!PREFIX!!/sbin/upsmond ]; then
	!!PREFIX!!/sbin/upsmond -p /dev/cuaa0 2>&1 > /dev/null && echo -n ' upsmond'
fi
