#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: mail
# REQUIRE: LOGIN
# KEYWORD: FreeBSD shutdown
#	we make mail start late, so that things like .forward's are not
#	processed until the system is fully operational

#
# Add the following lines to /etc/rc.conf to enable masqmail:
#
#masqmail_enable="YES"
#
# See masqmail(8) for flags
#

. %%RC_SUBR%%

name=masqmail
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/masqmail
required_dirs=/var/log/masqmail
required_files=%%PREFIX%%/etc/masqmail/masqmail.conf

start_precmd=start_precmd
stop_postcmd=stop_postcmd

extra_commands="reload"

start_precmd()
{
  case $sendmail_enable in
  [Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)
    warn "sendmail_enable should be set to NONE"
    ;;
  [Nn][Oo]|[Ff][Aa][Ll][Ss][Ee]|[Oo][Ff][Ff]|0)
    case $sendmail_submit_enable in
    [Yy][Ee][Ss]|[Tt][Rr][Uu][Ee]|[Oo][Nn]|1)
      warn "sendmail_submit_enable should be set to NO"
      ;;
    esac
    ;;
  [Nn][Oo][Nn][Ee])
    ;;
  esac
}

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

masqmail_enable=${masqmail_enable:-"NO"}
masqmail_flags=${masqmail_flags:-"-bd -q30m"}

load_rc_config $name
run_rc_command "$1"
