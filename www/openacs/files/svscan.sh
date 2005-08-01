#!/bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

# It would really, really be a Good Thing(tm)
# for you to enable some of the below
# control variables and the apropriate ulimit.
# These are only examples.
# Furthermore, you should think about additional
# limits you might need.
# Or, check login.conf(5) for a suitable
# alternative
#
# I really do suggest you use /var/service/ as your
# service spool directory. Check hier(7) for
# reasons.

# 10 Mb
MINSEGMENT=10240
# 20 Mb
#MAXSEGMENT=20480
# 10 Mb
MAXFILESIZE=10240
# 100
MAXFD=100
# 40
MAXCHILD=40

# ulimits
#ulimit -d ${MINSEGMENT}
#ulimit -f ${MAXFILESIZE}
#ulimit -m ${MAXSEGMENT}
#ulimit -n ${MAXFD}
#ulimit -s ${MINSEGMENT}
#ulimit -u ${MAXCHILD}

KILLALL=/usr/bin/killall
SVC=${PREFIX}/bin/svc
SVPROC=svscan
SVSCAN=$PREFIX/bin/svscan
READPROCTITLE=$PREFIX/bin/readproctitle
SVDIR=/var/service/

case "$1" in
  start)
	echo -n " svscan"
	exec env PATH=$PREFIX/sbin:$PREFIX/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:$PATH /bin/csh -cf "$SVSCAN $SVDIR |& $READPROCTITLE service errors: ................................................................................................................................................................................................................................................................................................................................................................................................................ &" > /dev/null
	;;

  stop)
	echo -n " svscan: "
	$KILLALL $SVPROC
	$SVC -dx $SVDIR/* $SVDIR/*/log
	;;

  *)
  	echo "Usage: $0 start | stop"
	;;
esac
