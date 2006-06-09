#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: spamass-milter
# REQUIRE: LOGIN
# BEFORE: mail
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable spamass-milter:
#
#spamass_milter_enable="YES"
#
# See spamass-milter(8) for flags.
#

. %%RC_SUBR%%

name=spamass_milter
rcvar=`set_rcvar`

command=%%PREFIX%%/sbin/spamass-milter
required_dirs=%%PREFIX%%/share/spamassassin

start_postcmd=start_postcmd
stop_postcmd=stop_postcmd

start_postcmd()
{
  if test -f /var/run/sendmail.pid
  then
	sleep 1
	kill -HUP `head -1 /var/run/sendmail.pid`
  fi
}

stop_postcmd()
{
  rm -f ${spamass_milter_socket}
  if test -f /var/run/sendmail.pid
  then
	sleep 1
	kill -HUP `head -1 /var/run/sendmail.pid`
  fi
}

# set defaults

spamass_milter_enable=${spamass_milter_enable:-"NO"}
spamass_milter_socket=${spamass_milter_socket:-"/var/run/spamass-milter.sock"}
spamass_milter_flags=${spamass_milter_flags:-"-f -p ${spamass_milter_socket}"}

load_rc_config ${name}
run_rc_command "$1"
