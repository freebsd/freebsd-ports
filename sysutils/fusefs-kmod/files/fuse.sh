#!/bin/sh
# $FreeBSD$

# PROVIDE: fusefs
# REQUIRE: sysctl
# KEYWORD: shutdown

[ -z "${fusefs_enable}" ]	&& fusefs_enable="NO"

kmod=fuse.ko
name=fusefs

. /etc/rc.subr

rcvar=`set_rcvar`

start_cmd="fusefs_start"
stop_cmd="fusefs_stop"

load_rc_config $name

fusefs_start()
{
	echo "Loading ${name}"
	kldload $kmod
}

fusefs_stop()
{
	echo "Unloading ${name}"
	kldunload $kmod
}

run_rc_command $*
