#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: cvsyncd
# REQUIRE: LOGIN
# KEYWORD: FreeBSD
#
cvsyncd_enable=${cvsyncd_enable-"NO"}
cvsyncd_pidfile=${cvsyncd_pidfile-"/var/run/cvsyncd.pid"}
cvsyncd_conffile=${cvsyncd_conffile-"%%PREFIX%%/etc/cvsyncd.conf"}

. %%RC_SUBR%%

name=cvsyncd
rcvar=`set_rcvar`
command=%%PREFIX%%/bin/${name}

load_rc_config ${name}

case "${cvsyncd_flags}" in
*-p\ *)
	echo "Warning: \$cvsyncd_flags includes -p option." \
		"Please use \$cvsyncd_pidfile instead."
	;;
*)
	cvsyncd_flags="-p ${cvsyncd_pidfile} ${cvsyncd_flags}" ;;
esac

case "${cvsyncd_flags}" in
*-c\ *)
	echo "Warning: \$cvsyncd_flags includes -c option." \
		"Please use \$cvsyncd_conffile instead."
	;;
*)
	cvsyncd_flags="-c ${cvsyncd_conffile} ${cvsyncd_flags}" ;;
esac

pidfile=${cvsyncd_pidfile}
required_files=${cvsyncd_conffile}

run_rc_command "$1"

