#! /bin/sh

if ! export PREFIX=$(expr $0 : "\(/.*\)/etc/cvsup/update\.sh\$"); then
    echo "$0: Cannot determine the PREFIX" >&2
    exit 1
fi

export CVSUP_ARGS="$*"
export PATH=/bin:/usr/bin:${PREFIX}/bin

lock=/var/spool/lock/cvsup.lock
log=/var/log/cvsup.log

# Rotate the log files

umask 22
test -f ${log}.7 && mv -f ${log}.7 ${log}.8
test -f ${log}.6 && mv -f ${log}.6 ${log}.7
test -f ${log}.5 && mv -f ${log}.5 ${log}.6
test -f ${log}.4 && mv -f ${log}.4 ${log}.5
test -f ${log}.3 && mv -f ${log}.3 ${log}.4
test -f ${log}.2 && mv -f ${log}.2 ${log}.3
test -f ${log}.1 && mv -f ${log}.1 ${log}.2
test -f ${log}.0 && mv -f ${log}.0 ${log}.1
test -f ${log}   && mv -f ${log}   ${log}.0
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
