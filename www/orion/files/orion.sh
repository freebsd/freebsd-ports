#!/bin/sh

# Set some variables
USER_NAME=%%USER_NAME%%
MYSELF=`basename $0`

case "$1" in
	start)
		su -f -m ${USER_NAME} -c "exec %%CONTROL_SCRIPT%% start" && echo -n ' %%APP_SHORTNAME%%'
		;;
	stop)
		su -f -m ${USER_NAME} -c "exec %%CONTROL_SCRIPT%% stop" && echo -n ' %%APP_SHORTNAME%%'
		;;
	*)
		echo ""
		echo "Usage: ${MYSELF} { start | stop }"
		echo ""
		exit 64
		;;
esac
