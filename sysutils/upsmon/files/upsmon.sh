#!/bin/sh

# see !!PREFIX!!/share/doc/upsmon/INSTALL for command line option details

if [ -x !!PREFIX!!/sbin/upsmon ]; then
	!!PREFIX!!/sbin/upsmon -p /dev/cuaa0 && echo -n ' upsmond'
fi
