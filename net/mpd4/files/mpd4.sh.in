#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: mpd
# REQUIRE: SERVERS
# BEFORE: DAEMON
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable mpd4:
# mpd_enable (bool):	Set to "NO" by default.
#			Set it to "YES" to enable mpd4.
# mpd_flags (string):	Set to "-b" by default.
#			Extra flags passed to start command.
#
# See mpd(8) for flags.
#

. %%RC_SUBR%%

name="mpd4"
rcvar=`set_rcvar mpd`

load_rc_config ${name}

: ${mpd_enable="NO"}
: ${mpd_flags="-b"}

pidfile="/var/run/${name}.pid"
command="%%PREFIX%%/sbin/${name}"
required_files="%%PREFIX%%/etc/${name}/mpd.conf %%PREFIX%%/etc/${name}/mpd.links"

case "${mpd_flags}" in
*-p\ *)
        echo "ERROR: \$mpd_flags includes -p option." \
                "PID file is already set to $pidfile."
        exit 1
        ;;
*)
        command_args="-p ${pidfile} ${mpd_flags}"
        ;;
esac

run_rc_command "$1"
