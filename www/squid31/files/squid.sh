#!/bin/sh
#
# $FreeBSD$
#
# --begin rcng
# PROVIDE: squid
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown
# 
# Note:
# Set "squid_enable=yes" in either /etc/rc.conf, /etc/rc.conf.local or
# /etc/rc.conf.d/squid to make this script actually do something. There
# you can also set squid_chdir, squid_user, and squid_flags.
#
# Please see squid(8), rc.conf(5) and rc(8) for further details.
#
# --end rcng

name=squid
command=%%PREFIX%%/sbin/squid
# --begin rcng
extra_commands=reload
reload_cmd="${command} -k reconfigure"
# --end rcng
stop_cmd="squid_stop"
squid_chdir=${squid_chdir:-%%PREFIX%%/squid/logs}
squid_enable=${squid_enable:-"NO"}
squid_flags=${squid_flags-"-D"}
squid_user=${squid_user:-%%SQUID_UID%%}
default_config=%%PREFIX%%/etc/squid/squid.conf

# --begin rcold
squid_stop() {
	echo -n " ${name}"
	${command} -k shutdown
	while ps -xcU ${squid_user} | grep -q squid; do
		sleep 2
	done
}

# --end rcold
# --begin rcng
squid_stop() {
	${command} -k shutdown
	run_rc_command poll
}

. %%RC_SUBR%%
rcvar=`set_rcvar`
load_rc_config ${name}

# squid(8) will not start if ${default_config} is not present so try
# to catch that beforehand via ${required_files} rather than make
# squid(8) crash.
# If you remove the default configuration file make sure to add
# '-f /path/to/your/squid.conf' to squid_flags

if [ -z "${squid_flags}" ]; then
	required_files=${default_config}
fi
required_dirs=${squid_chdir}
run_rc_command "$1"
# --end rcng
# --begin rcold
case $1 in
start)
	if [ -x "${command}" -a \
		\( -f "${default_config}" -o "${squid_flags}" \) ]; then
		echo -n " ${name}"
		(cd ${squid_chdir} && exec su -fm ${squid_user} -c \
			"${command} ${squid_flags}")
	fi
	;;
stop)
	if [ -x "${command}" ]; then
		${stop_cmd}
	fi
	;;
*)
	echo "usage: ${0##*/} {start|stop}" >&2
	exit 64
	;;
esac
exit 0
# --end rcold
