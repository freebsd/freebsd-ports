#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/multimedia/ffmpeg-devel/files/Attic/ffserver.sh,v 1.1 2004-12-05 18:12:41 lioux Exp $
#

# PROVIDE: ffserver
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable  ffserver:
#
#ffserver_enable="YES"
#
ffserver_enable="NO"

. %%RC_SUBR%%

name=ffserver
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/${name}
required_files=%%PREFIX%%/etc/ffserver.conf

load_rc_config ${name}
run_rc_command "$1"
