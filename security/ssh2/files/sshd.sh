#!/bin/sh
case "$1" in
	start)
		!!PREFIX!!/sbin/sshd 2> /dev/null
		echo -n ' sshd'
		;;
	stop)
		if [ -f /var/run/sshd2_22.pid ]; then
			kill -TERM `cat /var/run/sshd2_22.pid`
			rm -f /var/run/sshd2_22.pid
			echo -n ' sshd'
		fi
		;;
	restart)
		if [ -f /var/run/sshd2_22.pid ]; then
			kill -HUP `cat /var/run/sshd2_22.pid`
			echo 'sshd restarted'
		fi
		;;
	-h)
		echo "Usage: `basename $0` { start | stop | restart }"
		;;
	*)
		!!PREFIX!!/sbin/sshd
		echo -n ' sshd'
		;;
esac
