#!/bin/sh
#
# $FreeBSD: /tmp/pcvs/ports/net/minisapserver/files/Attic/sapserver.sh,v 1.3 2006-02-20 20:47:27 dougb Exp $
#

# PROVIDE: sapserver
# REQUIRE: NETWORKING
# KEYWORD: shutdown

#
# Add the following lines to /etc/rc.conf to enable sapserver:
#
#sapserver_enable="YES"
#
sapserver_enable="${sapserver_enable-NO}"

. %%RC_SUBR%%

name=sapserver
rcvar=`set_rcvar`

command=%%PREFIX%%/bin/${name}
required_files=%%PREFIX%%/etc/sap.cfg

load_rc_config ${name}
run_rc_command "$1"
