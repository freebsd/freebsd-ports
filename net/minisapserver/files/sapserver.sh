#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/minisapserver/files/Attic/sapserver.sh,v 1.1 2004-05-25 09:17:51 krion Exp $
#

# PROVIDE: sapserver
# REQUIRE: NETWORKING
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable sapserver:
#
#sapserver_enable="YES"
#
sapserver_enable="NO"

. %%RC_SUBR%%

name=sapserver
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/${name}
required_files=%%PREFIX%%/etc/sap.cfg

load_rc_config ${name}
run_rc_command "$1"
