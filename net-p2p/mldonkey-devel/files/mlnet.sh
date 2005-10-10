#!/bin/sh
#
# $FreeBSD$
#
# Under a BSDL license. Copyright 2005. Mario S F Ferreira <lioux@FreeBSD.org>

# PROVIDE: mlnet
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable mlnet:
#
#mlnet_enable="YES"
#mlnet_user=""
#mlnet_logfile=""
#

. /etc/rc.subr

name="mlnet"
rcvar=`set_rcvar`
command="%%PREFIX%%/bin/mlnet"
procname="%%PREFIX%%/bin/mlnet-real"

## hardcoded, cannot override
mlnet_pidfile="${HOME}/.mldonkey/mlnet.pid"

mlnet_check_vars()
{
  if [ -z "${mlnet_user}" ]; then
    mlnet_user=$(whoami)
  fi

  if [ "x${mlnet_user}" = "xroot" ]; then
    err 1 "You have to set mlnet_user to a non-root user for security reasons"
  fi
}

start_cmd="start_cmd"
start_cmd()
{
  mlnet_check_vars
  if [ -n "${mlnet_logfile}" ]; then
    mlnet_logcommand="-log_file ${mlnet_logfile}"
  fi

  su -l ${mlnet_user} -c "${command} \
	${mlnet_logcommand} \
	${mlnet_flags} \
	>/dev/null &"
}

load_rc_config "${name}"
: ${mlnet_enable="NO"}
: ${mlnet_user=""}
: ${mlnet_logfile=""}

run_rc_command "$1"
