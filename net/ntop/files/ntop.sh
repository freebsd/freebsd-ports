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
# The certificate is %%PREFIX%%/share/ntop/ntop-cert.pem
https_port='3001'

# Directory for ntop.access.log
logdir='/var/log'

# Specify any additional arguments here - see ntop(8)
additional_args='-E'

#
# End of user-configurable variables
#----------------------------------------------------------------------

args='-d -t0'

[ ! -z $interfaces ] && args="$args -i $interfaces"
[ ! -z $http_port ] && args="$args -w $http_port"
[ ! -z $https_port ] && args="$args -W $https_port"
[ ! -z $logdir ] && args="$args -a ${logdir}"
[ ! -z $userid ] && args="$args -u $userid"
[ ! -z "$additional_args" ] && args="$args $additional_args"

case "$1" in
start)
  [ -d $logdir ] && touch ${logdir}/ntop.access.log \
    && chown $userid ${logdir}/ntop.access.log
  [ -d %%PREFIX%%/share/ntop ] && cd %%PREFIX%%/share/ntop
  [ -x %%PREFIX%%/bin/ntop ] && %%PREFIX%%/bin/ntop $args \
    && echo -n ' ntop'
  ;;
stop)
  killall ntop >/dev/null 2>&1 && echo -n ' ntop'
  ;;
*)
  echo "Usage: `basename $0` {start|stop}" >&2
  exit 64
  ;;
esac

exit 0
