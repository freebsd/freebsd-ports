#!/bin/sh
#

# PROVIDE: quagga
# REQUIRE: netif routing
# KEYWORD: FreeBSD shutdown

#
# Add the following lines to /etc/rc.conf to enable quagga:
#
#quagga_enable="YES"
#

. %%RC_SUBR%%

name="quagga"
rcvar=`set_rcvar`


stop_postcmd=stop_postcmd

stop_postcmd()
{
  rm -f $pidfile
}

# set defaults

quagga_enable=${quagga_enable:-"NO"}
quagga_flags=${quagga_flags:-"-d"}
load_rc_config $name

QUAGGA_DAEMONS="zebra ripd ripng ospfd ospf6d bgpd"

quagga_cmd=$1

case "$1" in
    force*)
	quagga_cmd=${quagga_cmd#force}
	;;
    fast*)
	quagga_cmd=${quagga_cmd#fast}
	;;
esac

if [ ${quagga_cmd} = "stop" ]; then
    QUAGGA_DAEMONS=$(reverse_list ${QUAGGA_DAEMONS})
fi

for daemon in ${QUAGGA_DAEMONS}; do
    command=%%PREFIX%%/sbin/${daemon}
    required_files=%%SYSCONF_DIR%%/${daemon}.conf
    pidfile=%%LOCALSTATE_DIR%%/${daemon}.pid
    if [ ${quagga_cmd} = "start" -a ! -f ${required_files} ]; then
		continue
    fi
    if [ ${quagga_cmd} = "stop" -a -z $(check_process ${command}) ]; then
		continue
    fi
    run_rc_command "$1"
done
