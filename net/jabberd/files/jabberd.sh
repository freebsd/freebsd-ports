#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/jabberd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

USER="jabber"
RUNDIR="/var/jabberd/pid"
HOSTNAME=`/bin/hostname`

test -x ${PREFIX}/bin/jabberd || exit 1

export PATH=/sbin:/bin:/usr/bin:${PREFIX}/bin:${PREFIX}/sbin
umask 077

cd ${RUNDIR} || exit

case "$1" in
start)
    su -f -m ${USER} -c ${PREFIX}/bin/jabberd &
    echo -n ' jabberd'
    ;;
stop)
    killall -u ${USER} jabberd c2s resolver router s2s sm
    for file in c2s resolver router s2s sm
      do
      rm -f ${RUNDIR}/$file.pid
    done
    echo -n ' jabberd'
    ;;
*)
    echo "Usage: `basename $0` {start|stop}" >&2
    ;;
esac

exit 0
