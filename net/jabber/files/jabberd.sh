#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/jabberd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

USER="jabber"
RUNDIR="/var/tmp"
HOSTNAME=`/bin/hostname`

test -x ${PREFIX}/sbin/jabberd || exit 1

export PATH=/sbin:/bin:/usr/bin:${PREFIX}/bin:${PREFIX}/sbin
umask 077

echo -n " jabberd "
cd ${RUNDIR} || exit

case ${1:-start} in
start)
    su -f -m ${USER} -c "jabberd -B -h ${HOSTNAME} -c ${PREFIX}/etc/jabber.xml" ;;

stop)
    killall -SIGKILL -u ${USER} jabberd;
    rm -f ${RUNDIR}/jabber.pid;
esac
