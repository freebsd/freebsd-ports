#! /bin/sh

if [ $# -eq 0 -o "$1" = "start" ]; then
  if [ -x !!PREFIX!!/sbin/smtpfwdd ] ; then
    !!PREFIX!!/sbin/smtpfwdd
    echo " smtpfwdd"
  fi
fi
if [ "$1" = "stop" ]; then
  killall smtpfwdd
fi
