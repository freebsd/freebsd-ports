#!/bin/sh
#
# $FreeBSD$
#

# PROVIDE: %%NAME%%
# REQUIRE: syslogd
# BEFORE:  sendmail
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable milter-sender:
#
#%%NAME%%_enable="YES"
#

. %%RC_SUBR%%

name=%%NAME%%
rcvar=`set_rcvar`

# set defaults
%%NAME%%_enable=${%%NAME%%_enable:-"NO"}
%%NAME%%_chdir="/var/spool/milter-sender"
%%NAME%%_pidfile=${%%NAME%%_pidfile:-"$%%NAME%%_chdir/pid"}
%%NAME%%_flags=${%%NAME%%_flags:-"unix:$%%NAME%%_chdir/socket"}

command=%%PREFIX%%/sbin/milter-sender
required_dirs="$%%NAME%%_chdir"

start_cmd=start_cmd
start_cmd()
{
    if [ -s "$%%NAME%%_chdir/mutex" ]; then
	ipcrm -s `cat $%%NAME%%_chdir/mutex`
    fi
    rm -f $%%NAME%%_chdir/{mutex,socket} $%%NAME%%_pidfile
    cd $%%NAME%%_chdir && $command $%%NAME%%_flags >/dev/null &
}

load_rc_config $name
run_rc_command "$1"
