#!/bin/sh
# $FreeBSD$

# PROVIDE: mlnet
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

mlnet_enable=${mlnet_enable:-"NO"}
mlnet_http_port=${mlnet_http_port:-"4080"}
mlnet_logfile=${mlnet_logfile:-"/var/log/mlnet"}

. %%RC_SUBR%%

name=mlnet
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/${name}"
start_cmd="${name}_start"
stop_cmd="${name}_stop"

mlnet_conf="%%PREFIX%%/etc/mlnet.conf"
required_files="${mlnet_conf}"
mlnet_user=${mlnet_user:-"mlnet"}

if [ -r ${mlnet_conf} ] ; then
	. ${mlnet_conf}
fi

mlnet_url="http://"
if [ -n "${mlnet_http_user}" -a -n "${mlnet_http_password}" ] ; then
	mlnet_url="${mlnet_url}${mlnet_http_user}:${mlnet_http_password}@"
fi
mlnet_url="${mlnet_url}localhost:${mlnet_http_port}"

mlnet_start() {
	if checkyesno mlnet_enable ; then
		echo -n " mlnet"
		su ${mlnet_user} -c "${command} \
			${mlnet_flags} \
			-daemon \
			-http_port ${mlnet_http_port}" \
			>>${mlnet_logfile} 2>&1
	fi
}

mlnet_stop() {
	if checkyesno mlnet_enable ; then
		echo -n " mlnet"
		%%LOCALBASE%%/bin/wget --spider -q \
			"${mlnet_url}/submit?q=close_fds" \
			>>${mlnet_logfile} 2>&1
		%%LOCALBASE%%/bin/wget --spider -q \
			"${mlnet_url}/submit?q=save" \
			>>${mlnet_logfile} 2>&1
		%%LOCALBASE%%/bin/wget --spider -q \
			"${mlnet_url}/submit?q=kill" \
			>>${mlnet_logfile} 2>&1
	fi
}

load_rc_config ${name}
run_rc_command "$1"
