#!/bin/sh
#
# $FreeBSD$
#
# Under a BSDL license. Copyright 2005. Mario S F Ferreira <lioux@FreeBSD.org>

# PROVIDE: freenet
# REQUIRE: LOGIN
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable freenet:
#
#freenet_enable="YES"
#freenet_user=""
#

. /etc/rc.subr

name="freenet"
rcvar=`set_rcvar`
command="%%PREFIX%%/sbin/${name}"
extra_commands="configure"

freenet_check_vars()
{
  if [ -z "${freenet_user}" ]; then
    freenet_user=$(whoami)
  fi

  if [ "x${freenet_user}" = "xroot" ]; then
    err 1 "You have to set freenet_user to a non-root user for security reasons"
  fi
}

configure_cmd="configure_cmd"
configure_cmd()
{
  freenet_check_vars
  su -l ${freenet_user} -c "${command} -c"
}

start_cmd="start_cmd"
start_cmd()
{
  freenet_check_vars
  su -l ${freenet_user} -c "${command} -i"
}

stop_cmd="stop_cmd"
stop_cmd()
{
  freenet_check_vars
  su -l ${freenet_user} -c "${command} -o"
}

status_cmd="status_cmd"
status_cmd()
{
  echo "Can't check ${name} status"
}

load_rc_config "${name}"
: ${freenet_enable="NO"}
: ${freenet_user=""}

run_rc_command "$1"
