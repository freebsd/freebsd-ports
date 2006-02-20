#!/bin/sh
#
# $FreeBSD$
#
# Under a BSDL license. Copyright 2005. Mario S F Ferreira <lioux@FreeBSD.org>

# PROVIDE: amphetadesk
# REQUIRE: LOGIN
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable amphetadesk:
#
#amphetadesk_enable="YES"
#amphetadesk_user=""
#amphetadesk_pidfile=""
#

. /etc/rc.subr

name="amphetadesk"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/AmphetaDesk"
procname="%%PERL%%"

load_rc_config "${name}"
: ${amphetadesk_enable="NO"}
: ${amphetadesk_user=""}

if [ -n "${amphetadesk_user}" ]; then
  eval realpath ~${amphetadesk_user} >/dev/null 2>&1 &&
    amphetadesk_homedir="$(eval realpath ~${amphetadesk_user})"
fi

if [ -n "${amphetadesk_user}" -a -z "${amphetadesk_pidfile}" -a -n "${amphetadesk_homedir}" ]; then
  amphetadesk_pidfile="${amphetadesk_homedir}/.${name}/AmphetaDesk.pid"
fi

pidfile="${amphetadesk_pidfile:-${HOME}/.${name}/AmphetaDesk.pid}"

start_cmd="start_cmd"

start_precmd="amphetadesk_check_vars"
stop_precmd="amphetadesk_check_vars"
status_precmd="amphetadesk_check_vars"

amphetadesk_check_vars()
{
  if [ -z "${amphetadesk_user}" ]; then
    amphetadesk_user=$(whoami)
  fi

  if [ "x${amphetadesk_user}" = "xroot" ]; then
    err 1 "You have to set amphetadesk_user to a non-root user for security reasons"
  fi
}

start_cmd()
{
  su -l ${amphetadesk_user} \
	-c "env PIDFILE=${pidfile} ${command} &"
}

run_rc_command "$1"
