#!/bin/sh
#
# $FreeBSD$
#
# Exim hints database maintenance
# 
#   contributed by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
#

# If there is a global system configuration file, suck it in.
#
if [ -r /etc/defaults/periodic.conf ]; then
    . /etc/defaults/periodic.conf
    source_periodic_confs
fi

exim_tidydb_enable=${exim_tidydb_enable:-"YES"}
exim_tidydb=${exim_tidydb:-"/usr/local/sbin/exim_tidydb"}
exim_dbdir=${exim_dbdir:-"/var/spool/exim"}

case "$exim_tidydb_enable" in
    [Yy][Ee][Ss])
	echo ""
	echo "Tidying Exim hints databases:"
	for db in "$exim_dbdir"/db/*.lockfile; do
	    echo ""
	    "$exim_tidydb" "$exim_dbdir" `basename $db .lockfile`
	done
	rc=1;;

    *)  rc=0;;
esac

exit $rc
