#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/jabberd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi
user=jabber
rundir=/tmp
out=/var/log/jabber.log
hostname=`/bin/hostname`

export PATH=/bin:/usr/bin:${PREFIX}/bin
umask 077

test -x ${PREFIX}/bin/jabberd || exit 1
echo -n " jabberd"
cd ${rundir} || exit

arg=${1:-start}
case $arg in
start)
    su -f -m ${user} -c "jabberd -h ${hostname} -c ${PREFIX}/etc/jabber.xml" >${out} 2>&1 &;;

stop)
    killall jabberd;
    rm -f /var/tmp/jabber.pid;
esac
