#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/cvsupd\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi
base=${PREFIX}/etc/cvsup
out=/var/tmp/cvsupd.out

export PATH=/bin:/usr/bin:${PREFIX}/sbin
umask 2

test -x ${PREFIX}/sbin/cvsupd || exit 1
echo -n " cvsupd"
cd ${base} || exit
. ./config.sh || exit
su -m ${user} -c \
    "cvsupd -e -C ${maxclients} -l @${facility} -s sup.client" >>${out} 2>&1
