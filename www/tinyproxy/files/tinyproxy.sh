#!/bin/sh
if [ $# -eq 0 -o x$1 = xstart ]; then
  if [ -x %PREFIX%/sbin/tinyproxy ]; then
   %PREFIX%/sbin/tinyproxy && echo ' tinyproxy'
  fi
fi
if [ x$1 = xstop ]; then
  if [ -f /var/run/tinyproxy.pid ]; then
    kill `cat /var/run/tinyproxy.pid`
  else
    # oh well
    killall tinyproxy
  fi
fi
