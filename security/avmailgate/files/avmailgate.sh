#! /bin/sh

case "$1" in
	start)
		echo "Initializing SMTP port. (avmailgate)"
		/usr/local/sbin/avgated   -A /usr/local/etc/antivir/avmailgate.acl -C /usr/local/etc/antivir/avmailgate.conf &
		/usr/local/sbin/avgatefwd -C /usr/local/etc/antivir/avmailgate.conf &
		;;
	stop)
		echo -n "Shutting down SMTP port:"
		echo
		kill `cat /var/run/avmailgate_d.pid`
		kill `cat /var/run/avmailgate_fwd.pid`
		;;
	restart)
		"$0" stop
		"$0" start
		;;
	*)
		echo "Usage: $0 {start|stop|restart}"
		exit 1
		;;
esac

exit 0

