#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: amavisd-milter
# BEFORE: amavisd mail
# KEYWORD: FreeBSD shutdown

prefix=%%PREFIX%%

# Define these amavisd_milter_* variables in one of these files:
#	/etc/rc.conf
#	/etc/rc.conf.local
#
# DO NOT CHANGE THESE DEFAULT VALUES HERE
amavisd_milter_enable=no
amavisd_milter_flags="-D"
amavisd_milter_user=%%AMAVISUSER%%
#amavisd_milter_socket="inet:9999@127.0.0.1"
amavisd_milter_socket="local:/var/amavis/amavis-milter.sock"

. %%RC_SUBR%%

name="amavisd_milter"
rcvar=`set_rcvar`
start_precmd="amavisd_precmd"
stop_postcmd="remove_socket"
command=${prefix}/sbin/amavis-milter

# Remove the AMaViSd Milter Socket
remove_socket()
{
	case ${amavisd_milter_socket} in
		unix:*|local:*)
			socket=`echo ${amavisd_milter_socket} | /usr/bin/cut -d: -f2`
			if [ -S ${socket} ]; then
				rm -f ${socket}
			fi
			;;
		/*)
			if [ -S ${amavisd_milter_socket} ]; then
				rm -f ${amavisd_milter_socket}
			fi
			;;
	esac
}

amavisd_precmd()
{
	rc_flags="${rc_flags} -p ${amavisd_milter_socket}"

	remove_socket
}

load_rc_config $name
run_rc_command "$1"
