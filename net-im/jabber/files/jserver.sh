#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/jserver\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi
user=jserver
rundir=/tmp
out=${rundir}/jserver.out

export PATH=/bin:/usr/bin:${PREFIX}/bin
umask 077

test -x ${PREFIX}/bin/jserver || exit 1
echo -n " jserver"
cd ${rundir} || exit

arg=${1:-start}
case $arg in
start)
    su -f -m ${user} -c \
	"jserver" \
	>>${out} 2>&1 &;;

stop)
    killall jserver;;
esac
