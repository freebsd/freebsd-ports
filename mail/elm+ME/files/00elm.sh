#!/bin/sh
#
# $FreeBSD$
#
# Configure the shared library cache
#
# PROVIDE: elm
# REQUIRE: ldconfig
# KEYWORD: FreeBSD

elm_enable=${elm_enable:-"YES"}
elm_shlib_dir=${elm_shlib_dir:-"%%SHLIB_DIR%%"}

. %%RC_SUBR%%

name=ldconfig
rcvar=$(set_rcvar)
ldconfig_command="/sbin/ldconfig"
load_rc_config ${name}

name="elm"
rcvar=$(set_rcvar)
start_cmd="elm_start"
stop_cmd=":"

elm_start ()
{
	local _ins

	_ins=
	ldconfig=${ldconfig_command}
	checkyesno ldconfig_insecure && _ins="-i"
	if [ -x "${ldconfig_command}" ]; then
		${ldconfig} -m ${_ins} ${elm_shlib_dir}
	fi
}

load_rc_config ${name}
run_rc_command "$1"
