#!/bin/sh

# Set some variables
MYSELF=`basename $0`

case "$1" in
	start)
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% start" && echo -n ' %%APP_SHORTNAME%%'
		;;
	stop)
		su -f -m %%USER%% -c "exec %%CONTROL_SCRIPT%% stop" && echo -n ' %%APP_SHORTNAME%%'
		;;
	*)
		echo ""
		echo "Usage: ${MYSELF} { start | stop }"
		echo ""
		exit 64
		;;
esac
