#!/bin/sh
#
# $Id$
#
# Note that 'pidfile' may need to be changed if 'args' is altered; see
# the description of the 'pid_file_path' Exim configuration option in
# the Exim Specification.
#
args='-bd -q30m'
pidfile='/var/run/exim.pid'

case "$1" in
start)
        [ -x /usr/local/sbin/exim ] && /usr/local/sbin/exim ${args} && \
	    echo -n ' exim'
        ;;
stop)
        kill `cat ${pidfile}` && echo -n ' exim'
        ;;
*)
        echo "Usage: `basename $0` {start|stop}" >&2
        exit 64
        ;;
esac

exit 0

