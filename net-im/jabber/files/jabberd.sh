#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/jabberd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

USER="jabber"
RUNDIR="/var/tmp"
LOG="/var/log/jabber.log"
HOSTNAME=`/bin/hostname`

test -x ${PREFIX}/sbin/jabberd || exit 1

export PATH=/sbin:/bin:/usr/bin:${PREFIX}/bin:${PREFIX}/sbin
umask 077

echo -n " jabberd "
cd ${RUNDIR} || exit

case ${1:-start} in
start)
    su -f -m ${USER} -c "jabberd -h ${HOSTNAME} -c ${PREFIX}/etc/jabber.xml" >${LOG} 2>&1 &;;

stop)
    killall jabberd;
    rm -f ${RUNDIR}/jabber.pid;
esac
