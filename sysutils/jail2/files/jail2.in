#!/bin/sh

# Alternative rc script for jails. This script relies on
# /etc/jail.conf instead of rc.conf variables. Usage:
#
# jail2_enable	   -> Enables the script
# jail2_list	   -> List of jails to be started. The names
#				      must match the names in /etc/jail.conf
# jail2_$name_zfs  -> List of ZFS datasets to connect to the
#					  jail $name.
#
# To manage ZFS datasets within a jail the dataset must have
# set the parameter "jailed" to 1. Additionally the jail must
# have set the proberties "allow.mount", "allow.mount.zfs"
# and "enforce_statfs" to value lesser than 2.

# PROVIDE: jail
# REQUIRE: LOGIN cleanvar
# BEFORE: securelevel
# KEYWORD: shutdown

. /etc/rc.subr

name="jail2"
rcvar=jail2_enable

start_cmd="jail2_start"
stop_cmd="jail2_stop"

jail2_start()
{
	echo -n "Starting jails: "

	for _j in ${jail2_list}; do
		echo -n "${_j} "

		if [ -e /var/run/jail_${_j}.id ]; then
			echo "${_j} already exists"
			continue
		fi

		jail -c -i -J /var/run/jail_${_j}.id ${_j} > /dev/null 2>&1

		eval _zfs=\"\${jail2_${_j}_zfs:-}\"
		_jid=`jls -j ${_j} jid 2>/dev/null`

		if [ -n "${_zfs}" ]; then
			for _ds in ${_zfs}; do
				_jailed=`zfs get -H jailed ${_ds} 2>/dev/null | awk '{ print $3 }'`
				if [ "${_jailed}" = "on" ]; then
					echo "zfs jail "${_jid}" ${_ds} 2>/dev/null"
					zfs jail "${_jid}" ${_ds} 2>/dev/null
				fi
			done
		fi
	done

	echo
}

jail2_stop()
{
	echo -n "Stopping jails: "

	for _j in ${jail2_list}; do
     	echo -n "${_j} "

		if [ ! -e /var/run/jail_${_j}.id ]; then
			echo "${_j} doesn't exists"
			continue
		fi

		eval _zfs=\"\${jail2_${_j}_zfs:-}\"
		_jid=`jls -j ${_j} jid 2>/dev/null`

		jail -r -q ${_j} > /dev/null 2>&1
		rm /var/run/jail_${_j}.id

		if [ -n "${_zfs}" ]; then
			for _ds in ${_zfs}; do
				_jailed=`zfs get -H jailed ${_ds} 2>/dev/null | awk '{ print $3 }'`
				if [ "${_jailed}" = "on" ]; then
					echo "zfs unjail "${_jid}" ${_ds} 2>/dev/null"
					zfs unjail "${_jid}" ${_ds} 2>/dev/null
				fi
			done
		fi
	done

	echo
}

load_rc_config $name
: ${jail2_enable="NO"}

cmd="$1"
if [ $# -gt 0 ]; then
	shift
fi
if [ -n "$*" ]; then
	jail2_list="$*"
fi

run_rc_command "${cmd}"
