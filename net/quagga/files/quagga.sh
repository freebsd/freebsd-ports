#!/bin/sh
#

# PROVIDE: quagga
# REQUIRE: netif routing mountcritlocal
# BEFORE:  NETWORKING
# KEYWORD: FreeBSD NetBSD

#
# Add the following lines to /etc/rc.conf to enable quagga:
#
#quagga_enable="YES"
#
# You may also use next flags to tune startup
#quagga_flags="-d"
#quagga_daemons="zebra ripd ripng ospfd ospf6d bgpd"
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
quagga_daemons=${quagga_daemons:-"zebra ripd ripng ospfd ospf6d bgpd"}
load_rc_config $name

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
    quagga_daemons=$(reverse_list ${quagga_daemons})
fi

for daemon in ${quagga_daemons}; do
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
