#!/bin/sh

###
# Author: Light
# Email: isibane@gmail.com
###

usage()
{
	echo "Usage: `basename $0` [-a] | [-l] | [-L] | <service-name> [action]"
	echo -e "\t-h Show this message"
	echo -e "\t-a Show all service names"
	echo -e "\t-l Show system service names"
	echo -e "\t-L Show port service names"
	echo -e "\t-x Show X11 service names"
	exit 1
}

list_system() { find /etc/rc.d -type f -perm +a+x 2>/dev/null; }
list_ports() { find /usr/local/etc/rc.d -type f -perm +a+x 2>/dev/null; }
list_x11() { find /usr/X11R6/etc/rc.d -type f -perm +a+x 2>/dev/null; }
list_filter() { sed "s/.sh$//g;s/.*\\///g" | sort | column; }

set -- `getopt "ahlLx" "$@"` || {
	usage
}
while :
do
	case "$1" in
	-a) ( list_system; list_ports; list_x11) | list_filter; exit 0 ;;
	-l) list_system | list_filter; exit 0 ;;
	-L) list_ports | list_filter; exit 0 ;;
	-x) list_x11 | list_filter; exit 0 ;;
	-h) usage ;;
	--) break ;;
	esac
	shift
done
shift
if [ -z "$1" ]
then
	usage
fi
service_name=`( list_system; list_ports; list_x11 ) | grep -e "/$1[^/]*$\|/$1[^/]*\.sh$" | head -n 1`
if [ -z "$service_name" ]
then
	echo "Error: Unknown service '$1*[.sh]'"
	echo
	usage
else
	$service_name $2
fi
exit 0
