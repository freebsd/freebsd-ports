#!/bin/sh

# Set some variables
USER_NAME=%%USER_NAME%%
MYSELF=`basename $0`
CONTROL_SCRIPT=%%CONTROL_SCRIPT%%

case "$1" in
	start)
		su - ${USER_NAME} -c "%%CONTROL_SCRIPT%% start" > /dev/null ; echo -n
		;;
	stop)
		su - ${USER_NAME} -c "%%CONTROL_SCRIPT%% stop"
		;;
	restart)
		su - ${USER_NAME} -c "%%CONTROL_SCRIPT%% restart"
		;;
	*)
		echo ""
		echo "Usage: ${MYSELF} { start | stop | restart }"
		echo ""
		exit 64
		;;
esac
