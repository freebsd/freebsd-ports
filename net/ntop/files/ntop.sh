#!/bin/sh

#----------------------------------------------------------------------
# The following variables may be changed
#

# Network interface(s) to be monitored;
# may be blank, or comma-separated list
interfaces=''

# User to run ntop as; leave blank for root
userid='nobody'

# [IP:]port for serving HTTP; set to '0' to disable
http_port='3000'

# [IP:]port for serving HTTPS; set to '0' to disable
# The certificate is %%PREFIX%%/etc/ntop/ntop-cert.pem
https_port='3001'

# Directory for ntop.access.log
logdir='/var/log'

# Specify any additional arguments here - see ntop(8)
additional_args=''

#
# End of user-configurable variables
#----------------------------------------------------------------------

args='-d -L --set-pcap-nonblocking --skip-version-check'

[ ! -z $interfaces ] && args="$args -i $interfaces"
[ ! -z $http_port ] && args="$args -w $http_port"
[ ! -z $https_port ] && args="$args -W $https_port"
[ ! -z $logdir ] && args="$args -a ${logdir}/ntop.access.log"
[ ! -z $userid ] && args="$args -u $userid"
[ ! -z "$additional_args" ] && args="$args $additional_args"

case "$1" in
start)
  # is it the first time we run ntop
  [ ! -e %%DBDIR%%/ntop/ntop_pw.db ] && {
	# just in case...
	[ ! -d  %%DBDIR%%/ntop ] && {
		echo "Reinstalling database directory"
		mkdir -p  %%DBDIR%%/ntop
		chown -R $userid:$userid  %%DBDIR%%/ntop
	}
	%%PREFIX%%/bin/ntop -u $userid -A || exit 1
	echo "Now we can start ntop!"
  }
  if [ -d $logdir ]; then
    touch ${logdir}/ntop.access.log
    chown $userid ${logdir}/ntop.access.log
  fi
  if [ -x %%PREFIX%%/bin/ntop ]; then
    %%PREFIX%%/bin/ntop $args > /dev/null 2>&1 &
    echo -n ' ntop'
  fi
  ;;
stop)
  killall ntop > /dev/null 2>&1 && echo -n ' ntop'
  ;;
*)
  echo "Usage: `basename $0` {start|stop}" >&2
  exit 64
  ;;
esac

exit 0
