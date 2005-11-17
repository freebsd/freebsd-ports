#!/bin/sh
# 

# PROVIDE: sancp
# REQUIRE: DAEMON
# BEFORE: LOGIN
# KEYWORD: FreeBSD shutdown

# Add the following lines to /etc/rc.conf to enable sancp:
# sancp_enable (bool):	Set to YES to enable sancp
# 				Default: NO
# sancp_flags (str):		Extra flags passed to sancp
#				Default: -D
# sancp_interface (str):        Network interface to sniff
#                               Default: ""
# sancp_conf (str):		Sancp configuration file
#				Default: %%PREFIX%%/etc/sancp.conf
#

. %%RC_SUBR%%

name="sancp"
rcvar=`set_rcvar`

command="%%PREFIX%%/bin/sancp"

load_rc_config $name

[ -z "$sancp_enable" ]    && sancp_enable="NO"
[ -z "$sancp_conf" ]      && sancp_conf="%%PREFIX%%/etc/sancp.conf"
[ -z "$sancp_flags" ]     && sancp_flags="-D"

[ -n "$sancp_interface" ] && sancp_flags="$sancp_flags -i $sancp_interface"
[ -n "$sancp_conf" ]      && sancp_flags="$sancp_flags -c $sancp_conf"

run_rc_command "$1"
