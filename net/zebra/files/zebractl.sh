#! /bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/zebra/files/Attic/zebractl.sh,v 1.8 2002-08-04 20:04:50 sumikawa Exp $
#
# zebra start/stop script by "Andreas Klemm <andreas@FreeBSD.ORG>"
#

usage()
{
	echo "$0: usage: $0 [ start | stop | restart ]"
	exit 1
}

if [ $# -lt 1 ]; then
	echo "$0: error: one argument needed"; usage
elif [ $# -gt 1 ]; then
	echo "$0: error: only one argument needed"; usage
fi

case $1 in
	start)
		if [ ! -f !!PREFIX!!/etc/zebra/zebra.conf ]; then
			echo "error: zebra.conf config file is mandatory"
			exit 1
		fi
		[ -f !!PREFIX!!/etc/zebra/zebra.conf ] \
			&& !!PREFIX!!/sbin/zebra -d && echo -n ' zebra'
		[ -f !!PREFIX!!/etc/zebra/ripd.conf ] \
			&& !!PREFIX!!/sbin/ripd -d && echo -n ' ripd'
		[ -f !!PREFIX!!/etc/zebra/ripngd.conf ] \
			&& !!PREFIX!!/sbin/ripngd -d && echo -n ' ripngd'
		[ -f !!PREFIX!!/etc/zebra/ospfd.conf ] \
			&& !!PREFIX!!/sbin/ospfd -d && echo -n ' ospfd'
		[ -f !!PREFIX!!/etc/zebra/ospf6d.conf ] \
			&& !!PREFIX!!/sbin/ospf6d -d && echo -n ' ospf6d'
		[ -f !!PREFIX!!/etc/zebra/bgpd.conf ] \
			&& !!PREFIX!!/sbin/bgpd -d && echo -n ' bgpd'
		;;

	stop)
		[ -f !!PREFIX!!/etc/zebra/ripd.conf ] && killall ripd
		[ -f !!PREFIX!!/etc/zebra/ripngd.conf ] && killall ripngd
		[ -f !!PREFIX!!/etc/zebra/ospfd.conf ] && killall ospfd
		[ -f !!PREFIX!!/etc/zebra/ospf6d.conf ] && killall ospf6d
		[ -f !!PREFIX!!/etc/zebra/bgpd.conf ] && killall bgpd
		[ -f !!PREFIX!!/etc/zebra/zebra.conf ] &&  killall zebra
		;;
	restart)
		$0 stop
		$0 start
		;;

	*)	echo "$0: error: unknown option $1"
		usage
		;;
esac
exit 0
