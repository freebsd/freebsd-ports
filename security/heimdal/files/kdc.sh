#!/bin/sh

# Installation prefix for Heimdal
PREFIX="%%PREFIX%%"

# One of `none', `master', or `slave' 
KDC_ROLE=none
KDC_FLAGS=""
IPROP_MASTER_HOST=""

KDC="${PREFIX}/libexec/kdc"
KPASSWDD="${PREFIX}/libexec/kpasswdd"
# Uncomment to use CrackLib
#KPASSWDD_FLAGS="--check-library=${PREFIX}/lib/kpasswdd-cracklib.so"
IPROPD_MASTER="${PREFIX}/libexec/ipropd-master"
IPROPD_SLAVE="${PREFIX}/libexec/ipropd-slave"

case "${KDC_ROLE}" in
none)	run_kdc=0 run_master=0 run_slave=0 ;;
master)	run_kdc=1 run_master=1 run_slave=0 ;;
slave) 	run_kdc=1 run_master=0 run_slave=1 ;;
*)	echo "KDC_ROLE is not set." >&2
	exit 64
	;;
esac

do_start() {
    if test "${run_kdc}" -eq "1"; then
	${KDC} ${KDC_FLAGS} &
	test "${run_master}" -eq "1" && ${KPASSWDD} ${KPASSWDD_FLAGS} &
	test "${run_master}" -eq "1" && ${IPROPD_MASTER} &
	test "${run_slave}"  -eq "1" && ${IPROPD_SLAVE} ${IPROP_MASTER_HOST} &
    fi
    echo -n ' kdc'
}

do_stop() {
    for pid in kdc kpasswdd ipropd-master ipropd-slave; do
	test -f "/var/run/${pid}.pid" && kill `cat /var/run/${pid}.pid`
    done
    echo -n ' kdc'
}

do_restart() {
    do_stop
    sleep 1
    do_start
}

case "$1" in
start)		do_start   ;;
stop)		do_stop    ;;
restart)	do_restart ;;
*)
    echo "Usage: `basename $0` {start|stop}" >&2
    exit 64
    ;;
esac

exit 0
