#!/bin/sh

case "$1" in
	start)
		if [ -f LOCALBASE/sbin/bogom ]
		then
			LOCALBASE/sbin/bogom -u root & > /dev/null	
			echo -n ' milter-bogom' 
		fi
		;;
	stop)
		killall bogom
		sleep 3 # wait for bogom to exit
		;;

	*)
		echo ""
		echo "Usage: `basename $0` { start | stop }"
		echo ""
		;;
esac
exit 0;
