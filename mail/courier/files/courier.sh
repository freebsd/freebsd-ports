#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/mail/courier/files/Attic/courier.sh,v 1.3 2004-01-15 15:12:32 sergei Exp $
#
# Adapted for FreeBSD from courier.sysvinit
#
# NOTE: The 'restart' here does a "hard" stop, and a start.  Be gentle, use
# "courierd restart" for a kindler, gentler, restart.
#
# PROVIDE: mail
# REQUIRE: LOGIN
# BEFORE:  securelevel
# KEYWORD: FreeBSD shutdown
#
# NOTE for FreeBSD 5.0+:
# If you want this script to start with the base rc scripts
# move courier.sh to /etc/rc.d/courier

prefix="%%PREFIX%%"
exec_prefix="${prefix}"
sysconfdir="${prefix}/etc/courier"
sbindir="${exec_prefix}/sbin"
bindir="${exec_prefix}/bin"
libexecdir="${prefix}/libexec"
datadir="${prefix}/share/courier"

# Define these courier_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#	/etc/rc.conf.d/courier
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
#
courier_enable=${courier_enable:-"NO"}	# Run Courier-MTA (YES/NO).

. %%RC_SUBR%%

name="courier"
rcvar=`set_rcvar`

start_cmd="${name}_start"
stop_cmd="${name}_stop"
extra_commands="restart"

courier_start()
{	# First time after install create aliases.dat and makesmtpaccess.dat
	echo -n "Starting"

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
		echo -n " courierfilter"
		${sbindir}/courierfilter start
	fi

	if [ -x ${libexecdir}/authlib/authdaemond ]; then
		echo -n " authdaemond"
		${libexecdir}/authlib/authdaemond start
	fi

	if [ -x ${sbindir}/courierldapaliasd ]; then
		echo -n " courierldapaliasd"
		${sbindir}/courierldapaliasd start
	fi

	case "`cat ${sysconfdir}/calendarmode 2>/dev/null`" in
	net)
		if [ -x ${libexecdir}/courier/pcpd ]; then
			echo -n " pcpd"
			${libexecdir}/courier/pcpd start
		fi
		;;
	*)
		;;
	esac

	if [ -x ${libexecdir}/courier/sqwebmaild ]; then
		echo -n " webmail"
		${libexecdir}/courier/sqwebmaild start
	fi

	if [ -x ${sbindir}/courier ]; then
		echo -n " courierd"
		${sbindir}/courier start
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
				echo -n " esmtpd"
				${sbindir}/esmtpd start
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
				echo -n " esmtpd-msa"
				${sbindir}/esmtpd-msa start
			fi
			;;
		esac
	fi

	ESMTPDSSLSTART=""
	if [ -f ${sysconfdir}/esmtpd-ssl ]; then
		. ${sysconfdir}/esmtpd-ssl
		case $ESMTPDSSLSTART in
		[Yy]*)
			if [ -x $COURIERTLS \
			  -a -x ${sbindir}/esmtpd-ssl ]; then
				echo -n " esmtpd-ssl"
				${sbindir}/esmtpd-ssl start
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
				echo -n " imapd"
				${sbindir}/imapd start
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
					echo -n " imapd-ssl"
					${sbindir}/imapd-ssl start
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
				echo -n " pop3d"
				${sbindir}/pop3d start
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
					echo -n " pop3d-ssl"
					${sbindir}/pop3d-ssl start
				fi
			fi
			;;
		esac
	fi
	echo "."
}

courier_stop()
{	# kill courier services in the reverse order of starting them
	echo -n "Stopping"

	if [ -x ${sbindir}/pop3d-ssl ]; then
		echo -n " pop3d-ssl"
		${sbindir}/pop3d-ssl stop
	fi

	if [ -x ${sbindir}/pop3d ]; then
		echo -n " pop3d"
		${sbindir}/pop3d stop
	fi

	if [ -x ${sbindir}/imapd-ssl ]; then
		echo -n " imapd-ssl"
		${sbindir}/imapd-ssl stop
	fi

	if [ -x ${sbindir}/imapd ]; then
		echo -n " imapd"
		${sbindir}/imapd stop
	fi

	if [ -x ${sbindir}/esmtpd-ssl ]; then
		echo -n " esmtpd-ssl"
		${sbindir}/esmtpd-ssl stop
	fi

	if [ -x ${sbindir}/esmtpd-msa ]; then
		echo -n " esmtpd-msa"
		${sbindir}/esmtpd-msa stop
	fi

	if [ -x ${sbindir}/esmtpd ]; then
		echo -n " esmtpd"
		${sbindir}/esmtpd stop
	fi

	if [ -x ${sbindir}/courier ]; then
		echo -n " courierd"
		${sbindir}/courier stop
	fi

	if [ -x ${libexecdir}/courier/sqwebmaild ]; then
		echo -n " webmail"
		${libexecdir}/courier/sqwebmaild stop
	fi

	if [ -x ${libexecdir}/courier/pcpd ]; then
		echo -n " pcpd"
		${libexecdir}/courier/pcpd stop
	fi

	if [ -x ${sbindir}/courierldapaliasd ]; then
		echo -n " courierldapaliasd"
		${sbindir}/courierldapaliasd stop
	fi

	if [ -x ${libexecdir}/authlib/authdaemond ]; then
		echo -n " authdaemond"
		${libexecdir}/authlib/authdaemond stop
	fi

	if [ -x ${sbindir}/courierfilter ]; then
		echo -n " courierfilter"
		${sbindir}/courierfilter stop
	fi
	echo "."
}

load_rc_config $name
run_rc_command "$1"
