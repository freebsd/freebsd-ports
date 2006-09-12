#!/bin/sh
# $FreeBSD$

# PROVIDE: p0fanalyzer
# REQUIRE: DAEMON
# BEFORE: amavisd
# KEYWORD: FreeBSD

p0fanalyzer_enable="${p0fanalyzer_enable-NO}"

. /etc/rc.subr

name="p0fanalyzer"
rcvar=`set_rcvar`

start_cmd=p0fanalyzer_start
stop_cmd=p0fanalyzer_stop

p0fanalyzer_start() {
	checkyesno p0fanalyzer_enable && echo "Starting p0f-analyzer." && \
	    /usr/sbin/daemon -p /var/run/p0fanalyzer1.pid \
	    /usr/local/bin/p0f -i bge0 -l 'tcp dst port 25' 2>&1 | \
	    /usr/sbin/daemon -p /var/run/p0fanalyzer2.pid \
	    /usr/local/sbin/p0f-analyzer.pl 2345
}

p0fanalyzer_stop() {
	/bin/kill `cat /var/run/p0fanalyzer2.pid`
	/bin/kill `cat /var/run/p0fanalyzer1.pid`
}

load_rc_config $name
run_rc_command "$1"
