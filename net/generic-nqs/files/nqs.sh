#!/bin/sh
#

# PROVIDE: nqs
# REQUIRE: NETWORKING SERVERS
# BEFORE: LOGIN
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable NQS:
# nqs_enable (bool):      Set to "NO" by default.
#                             Set it to "YES" to enable NQS

. /etc/rc.subr

name="nqs"
rcvar=`set_rcvar`

prefix="XXXX"
logfile="/var/log/nqs.log"
start_cmd="nqs_start"
stop_cmd="nqs_stop"
load_rc_config $name

nqs_start()
{
	${prefix}/sbin/nqsdaemon >> ${logfile} 2>&1 && echo 'Starting nqs.'
}

nqs_stop()
{
	/usr/bin/killall -KILL nqsdaemon netdaemon loaddaemon && echo 'Stopping nqs.'
}

run_rc_command "$1"
