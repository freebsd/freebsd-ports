#! /bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/quagga/files/Attic/zebractl.sh,v 1.2 2003-11-05 15:19:55 bms Exp $
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
		if [ ! -f !!SYSCONF_DIR!!/zebra.conf ]; then
			echo "error: zebra.conf config file is mandatory"
			exit 1
		fi
		[ -f !!SYSCONF_DIR!!/zebra.conf ] \
			&& !!PREFIX!!/sbin/zebra -d && echo -n ' zebra'
		[ -f !!SYSCONF_DIR!!/ripd.conf ] \
			&& !!PREFIX!!/sbin/ripd -d && echo -n ' ripd'
		[ -f !!SYSCONF_DIR!!/ripngd.conf ] \
			&& !!PREFIX!!/sbin/ripngd -d && echo -n ' ripngd'
		[ -f !!SYSCONF_DIR!!/ospfd.conf ] \
			&& !!PREFIX!!/sbin/ospfd -d && echo -n ' ospfd'
		[ -f !!SYSCONF_DIR!!/ospf6d.conf ] \
			&& !!PREFIX!!/sbin/ospf6d -d && echo -n ' ospf6d'
		[ -f !!SYSCONF_DIR!!/bgpd.conf ] \
			&& !!PREFIX!!/sbin/bgpd -d && echo -n ' bgpd'
		;;

	stop)
		[ -f !!SYSCONF_DIR!!/ripd.conf ] && killall ripd
		[ -f !!SYSCONF_DIR!!/ripngd.conf ] && killall ripngd
		[ -f !!SYSCONF_DIR!!/ospfd.conf ] && killall ospfd
		[ -f !!SYSCONF_DIR!!/ospf6d.conf ] && killall ospf6d
		[ -f !!SYSCONF_DIR!!/bgpd.conf ] && killall bgpd
		[ -f !!SYSCONF_DIR!!/zebra.conf ] &&  killall zebra
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
