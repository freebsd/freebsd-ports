#!/bin/sh
# -*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# Orion startup script.
#
# $FreeBSD$
#


# Set some variables
MYSELF=`basename $0`

case "$1" in
	start)
		truncate -s 0 %%PID_FILE%%
		chown %%USER%%:%%GROUP%% %%PID_FILE%%
		chmod 600 %%PID_FILE%%
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% start > /dev/null" && echo -n ' %%APP_SHORTNAME%%'
		;;
	stop)
		chown %%USER%%:%%GROUP%% %%PID_FILE%%
		chmod 600 %%PID_FILE%%
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% stop > /dev/null" && echo -n ' %%APP_SHORTNAME%%'
		;;
	*)
		echo ""
		echo "Usage: ${MYSELF} { start | stop }"
		echo ""
		exit 64
		;;
esac
