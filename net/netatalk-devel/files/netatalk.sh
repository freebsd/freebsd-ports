#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/netatalk-devel/files/Attic/netatalk.sh,v 1.4 2004-07-21 19:56:30 marcus Exp $
#
# PROVIDE: netatalk
# REQUIRE: DAEMON
# KEYWORD: FreeBSD
#
# AppleTalk daemons. Make sure not to start atalkd in the background:
# its data structures must have time to stablize before running the
# other processes.
#

. %%RC_SUBR%%

name=netatalk
rcvar=`set_rcvar`
hostname=`hostname -s`

start_cmd=netatalk_start
stop_cmd=netatalk_stop

netatalk_start() {
    checkyesno atalkd_enable && %%PREFIX%%/sbin/atalkd
    checkyesno atalkd_enable && \
    	%%PREFIX%%/bin/nbprgstr -p 4 ${hostname}:Workstation &
    checkyesno atalkd_enable && \
    	%%PREFIX%%/bin/nbprgstr -p 4 ${hostname}:netatalk &
    checkyesno papd_enable && %%PREFIX%%/sbin/papd
    checkyesno cnid_metad_enable && %%PREFIX%%/sbin/cnid_metad
    checkyesno afpd_enable && \
    	%%PREFIX%%/sbin/afpd -s %%PREFIX%%/etc/AppleVolumes.system \
	-f %%PREFIX%%/etc/AppleVolumes.default
    checkyesno timelord_enable && %%PREFIX%%/sbin/timelord
}

netatalk_stop() {
    checkyesno timelord_enable && killall timelord
    checkyesno afpd_enable && killall afpd
    checkyesno cnid_metad_enable && killall cnid_metad
    checkyesno papd_enable && killall papd
    checkyesno atalkd_enable && killall atalkd
}

[ -z "$netatalk_enable" ]	&& netatalk_enable="NO"
[ -z "$atalkd_enable" ]		&& atalkd_enable="NO"
[ -z "$papd_enable" ]		&& papd_enable="NO"
[ -z "$cnid_metad_enable" ]	&& cnid_metad_enable="NO"
[ -z "$afpd_enable" ]		&& afpd_enable="NO"
[ -z "$timelord_enable" ]	&& timelord_enable="NO"

load_rc_config ${name}
run_rc_command "$1"
