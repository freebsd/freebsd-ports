#!/bin/sh
# $FreeBSD: /tmp/pcvs/ports/mail/courier/files/Attic/courier.sh,v 1.1 2002-01-15 06:17:27 dwhite Exp $
#
# This is the ${PREFIX}/etc/rc.d file for Courier SMTP, IMAP and POP3 servers
#
# Adapted for FreeBSD from courier.sysvinit
#
# NOTE: The 'restart' here does a "hard" stop, and a start.  Be gentle, use
# "courierd restart" for a kindler, gentler, restart.
#

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
	echo "$0: Cannot determine the PREFIX" >&2
	exit 1
fi

prefix="${PREFIX}"
exec_prefix="${prefix}"
sysconfdir="${prefix}/etc/courier"
sbindir="${exec_prefix}/sbin"
libexecdir="${prefix}/libexec"
datadir="${prefix}/share/courier"

arg=${1:-start}
case $arg in
start)	# First time after install create aliases.dat and makesmtpaccess.dat

	if [ ! -f ${sysconfdir}/aliases.dat \
	  -a -x ${sbindir}/makealiases ]; then
		${sbindir}/makealiases
	fi

	esmtpdcert=0

	ESMTPDSTART=""
	if [ -f ${sysconfdir}/esmtpd ]; then
		. ${sysconfdir}/esmtpd
		case $ESMTPDSTART in
		[Yy]*)
			esmtpdcert=1
			;;
		esac
		if [ ! -f ${sysconfdir}/esmtpacceptmailfor.dat \
		  -a -x ${sbindir}/makeacceptmailfor ]; then
			${sbindir}/makeacceptmailfor
		fi
		if [ ! -f ${sysconfdir}/${ACCESSFILE}.dat \
		  -a -x ${sbindir}/makesmtpaccess ]; then
			${sbindir}/makesmtpaccess
		fi
	fi

	ESMTPDSTART=""
	if [ -f ${sysconfdir}/esmtpd-msa ]; then
		. ${sysconfdir}/esmtpd-msa
		case $ESMTPDSTART in
		[Yy]*)
			esmtpdcert=1
			;;
		esac
		if [ ! -f ${sysconfdir}/${ACCESSFILE}.dat \
		  -a -x ${sbindir}/makesmtpaccess-msa ]; then
			${sbindir}/makesmtpaccess-msa
		fi
	fi

	if [ -x ${sbindir}/courierfilter ]; then
		${sbindir}/courierfilter start && echo -n " courierfilter"
	fi

	if [ -x ${libexecdir}/authlib/authdaemond ]; then
		${libexecdir}/authlib/authdaemond start && echo -n " authdaemond"
	fi

	if [ -x ${sbindir}/courierldapaliasd ]; then
		${sbindir}/courierldapaliasd start && echo -n " courierldapaliasd"
	fi

	case "`cat ${sysconfdir}/calendarmode 2>/dev/null`" in
	net)
		if [ -x ${libexecdir}/courier/pcpd ]; then
			${libexecdir}/courier/pcpd start && echo -n " pcpd"
		fi
		;;
	*)
		;;
	esac

	if [ -x ${sbindir}/courier ]; then
		${sbindir}/courier start && echo -n " courierd"
	fi

	if [ "$esmtpdcert" = 1 ]; then
		# If we do not have a certificate, make one up.
		if [ ! -f ${sysconfdir}/esmtpd.pem \
		  -a -x $COURIERTLS \
		  -a -x ${sbindir}/mkesmtpdcert ]; then
			echo -n " generating-ESMTP-SSL-certificate..."
			${sbindir}/mkesmtpdcert >/dev/null 2>&1
		fi
	fi

	ESMTPDSTART=""
	if [ -f ${sysconfdir}/esmtpd ]; then
		. ${sysconfdir}/esmtpd
		case $ESMTPDSTART in
		[Yy]*)
			if [ -x ${sbindir}/esmtpd ]; then
				${sbindir}/esmtpd start && echo -n " esmtpd"
			fi
			;;
		esac
	fi

	ESMTPDSTART=""
	if [ -f ${sysconfdir}/esmtpd-msa ]; then
		. ${sysconfdir}/esmtpd-msa
		case $ESMTPDSTART in
		[Yy]*)
			if [ -x ${sbindir}/esmtpd-msa ]; then
				${sbindir}/esmtpd-msa start && echo -n " esmtpd-msa"
			fi
			;;
		esac
	fi

	IMAPDSTART=""
	if [ -f ${sysconfdir}/imapd ]; then
		. ${sysconfdir}/imapd
		case $IMAPDSTART in
		[Yy]*)
			if [ -x ${sbindir}/imapd ]; then
				${sbindir}/imapd start && echo -n " imapd"
			fi
			;;
		esac
	fi

	IMAPDSSLSTART=""
	if [ -f ${sysconfdir}/imapd-ssl ]; then
		. ${sysconfdir}/imapd-ssl
		case $IMAPDSSLSTART in
		[Yy]*)	# If we do not have a certificate, make one up.
			if [ -x $COURIERTLS ]; then
				if [ ! -f ${sysconfdir}/imapd.pem \
				  -a -x ${sbindir}/mkimapdcert ]; then
					echo -n " generating-IMAP-SSL-certificate..."
					${sbindir}/mkimapdcert >/dev/null 2>&1
				fi
				if [ -x ${sbindir}/imapd-ssl ]; then
					${sbindir}/imapd-ssl start && echo -n " imapd-ssl"
				fi
			fi
			;;
		esac
	fi

	POP3DSTART=""
	if [ -f ${sysconfdir}/pop3d ]; then 
		. ${sysconfdir}/pop3d
		case $POP3DSTART in
		[Yy]*)
			if [ -x ${sbindir}/pop3d ]; then
				${sbindir}/pop3d start && echo -n " pop3d"
			fi
			;;
		esac
	fi

	POP3DSSLSTART=""
	if [ -f ${sysconfdir}/pop3d-ssl ]; then
		. ${sysconfdir}/pop3d-ssl
		case $POP3DSSLSTART in
		[Yy]*)	# If we do not have a certificate, make one up.
			if [ -x $COURIERTLS ]; then
				if [ ! -f ${sysconfdir}/pop3d.pem \
				  -a -x ${sbindir}/mkpop3dcert ]; then
					echo -n " generating-POP3-SSL-certificate..."
					${sbindir}/mkpop3dcert >/dev/null 2>&1
				fi
				if [ -x ${sbindir}/pop3d-ssl ]; then
					${sbindir}/pop3d-ssl start && echo -n " pop3d-ssl"
				fi
			fi
			;;
		esac
	fi
	;;
stop)	# kill courier services in the reverse order of starting them
	if [ -x ${sbindir}/pop3d-ssl ]; then
		${sbindir}/pop3d-ssl stop && echo -n " pop3d-ssl"
	fi

	if [ -x ${sbindir}/pop3d ]; then
		${sbindir}/pop3d stop && echo -n " pop3d"
	fi

	if [ -x ${sbindir}/imapd-ssl ]; then
		${sbindir}/imapd-ssl stop && echo -n " imapd-ssl"
	fi

	if [ -x ${sbindir}/imapd ]; then
		${sbindir}/imapd stop && echo -n " imapd"
	fi

	if [ -x ${sbindir}/esmtpd-msa ]; then
		${sbindir}/esmtpd-msa stop && echo -n " esmtpd-msa"
	fi
	
	if [ -x ${sbindir}/esmtpd ]; then
		${sbindir}/esmtpd stop && echo -n " esmtpd"
	fi

	if [ -x ${sbindir}/courier ]; then
		${sbindir}/courier stop && echo -n " courierd"
	fi

	if [ -x ${libexecdir}/courier/pcpd ]; then
		${libexecdir}/courier/pcpd stop && echo -n " pcpd"
	fi

	if [ -x ${sbindir}/courierldapaliasd ]; then
		${sbindir}/courierldapaliasd stop && echo -n " courierldapaliasd"
	fi

	if [ -x ${libexecdir}/authlib/authdaemond ]; then
		${libexecdir}/authlib/authdaemond stop && echo -n " authdaemond"
	fi

	if [ -x ${sbindir}/courierfilter ]; then
		${sbindir}/courierfilter stop && echo " courierfilter"
	fi
	;;
restart)
	$0 stop
	$0 start
	;;
*)
	echo ""
	echo "Usage: `basename $0` { start | stop | restart }"
	echo ""
	exit 64
	;;
esac
exit 0
