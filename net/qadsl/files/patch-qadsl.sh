*** /dev/null	Thu Dec 13 22:20:21 2001
--- qadsl.sh	Wed Dec 12 21:05:26 2001
***************
*** 0 ****
--- 1,21 ----
+ #!/bin/sh
+ 
+ if ! PREFIX=$(expr $0 : "\(/.*\)/etc/rc\.d/$(basename $0)\$"); then
+     echo "$0: Cannot determine the PREFIX" >&2
+     exit 1
+ fi
+ 
+ case "$1" in
+ start)
+ 	[ -x ${PREFIX}/sbin/qadsl ] && ( ${PREFIX}/sbin/qadsl -l & ) 
+ 	sleep 2
+ 	;;
+ stop)
+ 	killall qadsl && echo -n ' qadsl'
+ 	;;
+ *)
+ 	echo "Usage: `basename $0` {start|stop}" >&2
+ 	;;
+ esac
+ 
+ exit 0
