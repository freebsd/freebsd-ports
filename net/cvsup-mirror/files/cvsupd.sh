#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/cvsupd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi
base=${PREFIX}/etc/cvsup
rundir=/var/run
out=${rundir}/cvsupd.out

export PATH=/bin:/usr/bin:${PREFIX}/sbin
umask 2

test -x ${PREFIX}/sbin/cvsupd || exit 1
echo -n " cvsupd"
cd ${rundir} || exit
. ${base}/config.sh || exit

arg=${1:-start}
case $arg in
start)
    (umask 22 && touch ${out}) || exit
    su -f -m ${user} -c \
	"cvsupd -e -C 100 -l @${facility} -b ${base} -s sup.client" \
	>>${out} 2>&1;;

stop)
    killall cvsupd;;
esac
