#!/bin/sh
#
# $FreeBSD$
#
# Check for rejected mail
# Log lines that end with ' : IGNORE' will not be reported
# 
#   contributed by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
#

# If there is a global system configuration file, suck it in.
#
if [ -r /etc/defaults/periodic.conf ]
then
    . /etc/defaults/periodic.conf
    source_periodic_confs
fi

: ${exim_status_mail_rejects_enable="YES"}
: ${exim_status_mail_rejects_logs=2}
: ${exim_rejectlog="%%LOGDIR%%/rejectlog"}

case "$exim_status_mail_rejects_enable" in
    [Yy][Ee][Ss])
	if [ ! -d `dirname "$exim_rejectlog"` ]
	then
	    echo '$exim_status_mail_rejects_enable is set but' \
		"`dirname "$exim_rejectlog"` doesn't exist"
	    rc=2
	elif [ "$exim_status_mail_rejects_logs" -le 0 ]
	then
	    echo '$exim_status_mail_rejects_enable is set but' \
		'$exim_status_mail_rejects_logs is not greater than zero'
	    rc=2
	else
	    echo
	    echo "Checking for rejected mail:"

	    start=`date -v-1d '+%Y-%m-%d'`
	    n=$(($exim_status_mail_rejects_logs - 2))
	    rc=$({
		while [ $n -ge 0 ]
		do
		    if [ -f "$exim_rejectlog.$n" ]
		    then
			cat "$exim_rejectlog.$n"
		    elif [ -f "$exim_rejectlog.$n.gz" ]
		    then
			zcat -fc "$exim_rejectlog.$n.gz"
		    elif [ -f "$exim_rejectlog.$n.bz2" ]
		    then
			bzcat -fc "$exim_rejectlog.$n.bz2"
		    fi
		    n=$(($n - 1))
		done
		if [ -f "$exim_rejectlog" ]
		then
		    cat "$exim_rejectlog"
		fi
	    } |
		grep -e "^$start" | grep -v ' : IGNORE$' | tee /dev/stderr | wc -l)
	    [ $rc -gt 0 ] && rc=1
	fi;;

    *)  rc=0;;
esac

exit $rc
