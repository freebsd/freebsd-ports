#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: slapd
# REQUIRE: NETWORKING SERVERS
# BEFORE: DAEMON
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable slapd:
#
#slapd_enable="YES"
#slapd_flags='-h "ldapi://%2fvar%2frun%2fopenldap%2fldapi/ ldap://0.0.0.0/"'
#slapd_sockets="/var/run/openldap/ldapi"
#
# See slapd(8) for more flags
#
# The `-u' and `-g' flags are automatically extracted from slapd_owner,
# by default slapd runs under the non-privileged user id `ldap'. If you
# want to run slapd as root, override this in /etc/rc.conf with
#
#slapd_owner="DEFAULT"
#

. %%RC_SUBR%%

name=slapd
rcvar=`set_rcvar`

command=%%PREFIX%%/libexec/slapd
pidfile=%%LDAP_RUN_DIR%%/slapd.pid
required_dirs=%%LDAP_RUN_DIR%%
required_files=%%PREFIX%%/etc/openldap/slapd.conf

start_precmd=start_precmd
start_postcmd=start_postcmd

# extract user and group, adjust ownership of directories and database

start_precmd()
{
  case x"$slapd_owner" in
  x|x[Nn][Oo][Nn][Ee]|x[Dd][Ee][Ff][Aa][Uu][Ll][Tt])
    ;;
  x*)
    chown "$slapd_owner" "%%LDAP_RUN_DIR%%"
    chown -RL "$slapd_owner" "%%DATABASEDIR%%"
    chown "$slapd_owner" "%%PREFIX%%/etc/openldap/slapd.conf"

    slapd_ownername=`expr //"$slapd_owner" : //'\([^:]*\)'`
    slapd_groupname=`expr //"$slapd_owner" : //'.*:\([^:]*\)'`

    if [ -n "$slapd_ownername" ]; then
      rc_flags="$rc_flags -u $slapd_ownername"
    fi
    if [ -n "$slapd_groupname" ]; then
      rc_flags="$rc_flags -g $slapd_groupname"
    fi
    ;;
  esac
}

# adjust ownership of created unix sockets

start_postcmd()
{
  for socket in $slapd_sockets; do
    for seconds in 1 2 3 4 5; do
      [ -e "$socket" ] && break
      sleep 1
    done
    if [ -S "$socket" ]; then
      case x"$slapd_owner" in
      x|x[Nn][Oo][Nn][Ee]|x[Dd][Ee][Ff][Aa][Uu][Ll][Tt])
        ;;
      x*)
        chown "$slapd_owner" "$socket"
        ;;
      esac
      chmod "$slapd_sockets_mode" "$socket"
    fi
  done
}

# set defaults

[ -z "$slapd_enable" ]       && slapd_enable=NO
[ -z "$slapd_flags" ]        && slapd_flags=

[ -z "$slapd_owner" ]        && slapd_owner=ldap:ldap
[ -z "$slapd_sockets" ]      && slapd_sockets=
[ -z "$slapd_sockets_mode" ] && slapd_sockets_mode=666

load_rc_config $name

if [ -n "$slapd_args" ]; then
  warn "slapd_args is deprecated, use slapd_flags"
  slapd_flags="$slapd_args"
fi

run_rc_command "$1"
