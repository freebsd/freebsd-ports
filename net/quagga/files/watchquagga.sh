#!/bin/sh
#

# PROVIDE: watchquagga
# REQUIRE: netif routing mountcritlocal quagga
# BEFORE:  NETWORKING
# KEYWORD: FreeBSD NetBSD

#
# Add the following line to /etc/rc.conf to enable quagga:
#watchquagga_enable="YES"
#
# You may also wish to use the following variables to fine-tune startup:
#watchquagga_flags=""
#
#

. %%RC_SUBR%%

name="watchquagga"
rcvar=`set_rcvar`


stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

watchquagga_enable=${watchquagga_enable:-"NO"}
watchquagga_flags=${watchquagga_flags:-""}
load_rc_config $name

command=%%PREFIX%%/sbin/watchquagga
pidfile=%%LOCALSTATE_DIR%%/watchquagga.pid
run_rc_command "$1"
