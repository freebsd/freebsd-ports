#!/bin/sh
#
# $FreeBSD$
#
# PROVIDE: swatch
# REQUIRE: DAEMON
#
# To enable multiple instance of swatch, add lines like below to
# /etc/rc.conf.
#
# swatch_enable="YES"
# swatch_rules="1 2 3"
# swatch_1_flags="--config-file=/rc --tail-file=/log --daemon --pid-file=/pid"
# swatch_1_user="nobody"
# swatch_1_chdir="/var/tmp"
# swatch_1_pidfile="/pid"
# swatch_2_flags="blah, blah"
# swatch_3_flags="blah, blah"

. %%RC_SUBR%%

name=swatch
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/swatch
sig_stop=SIGTERM

load_rc_config ${name}

if [ -n "${swatch_rules}" ]; then
    for i in ${swatch_rules}; do
	eval swatch_flags=\$swatch_${i}_flags
	eval swatch_user=\$swatch_${i}_user
	eval swatch_chdir=\$swatch_${i}_chdir
	eval pidfile=\$swatch_${i}_pidfile
	run_rc_command "$1"
    done
fi
