#! /bin/sh

if ! PREFIX=$(expr $0 : "\(/.*\)/etc/cvsup/update\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

export PREFIX
export CVSUP_ARGS="$*"
export PATH=/bin:/usr/bin:${PREFIX}/bin

lock=/var/spool/lock/cvsup.lock
log=/var/log/cvsup.log

num_logs=8
use_gzip=0

if [ ${use_gzip} != 0 ]
then
	gz_ext=.gz
fi

# Rotate the log files

umask 22

for i in $(/usr/bin/jot ${num_logs} $((${num_logs}-1)) 0)
do
	test -f ${log}.$i${gz_ext} && mv -f ${log}.$i${gz_ext} ${log}.$(($i+1))${gz_ext}
done

test -f ${log}   && mv -f ${log}   ${log}.0 && [ ${use_gzip} != 0 ] && /usr/bin/gzip -9 ${log}.0
exec >${log} 2>&1

# Do the update

date "+CVSup update begins at %Y-%m-%d %T"

# The rest of this is executed while holding the lock file, to ensure that
# multiple instances won't collide with one another.

lockf -t 0 ${lock} /bin/sh << 'E*O*F'

base=${PREFIX}/etc/cvsup
rundir=/var/tmp
cd ${rundir} || exit
. ${base}/config.sh || exit

colldir=sup.client
startup=${PREFIX}/etc/rc.d
eval chome=~${cuser}
cmd="exec env HOME=${chome} cvsup"
options="-1gL 1 -b ${base} -c ${colldir} ${CVSUP_ARGS}"

umask 2
ok=yes

echo "Updating from ${host}"
su -f -m ${cuser} -c \
    "${cmd} ${options} -h ${host} ${base}/supfile" || ok=no

if [ ${ok} = yes ]; then
    if [ -f ${base}/.start_server ]; then
	if [ -x ${startup}/cvsupd.sh ]; then
	    echo -n "Starting the server:"
	    /bin/sh ${startup}/cvsupd.sh start
	    echo "."
	fi
	rm -f ${base}/.start_server
    fi
fi

E*O*F

date "+CVSup update ends at %Y-%m-%d %T"
