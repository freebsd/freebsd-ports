--- ddupcron.sh.orig	Sun Oct 22 19:11:48 2000
+++ ddupcron.sh	Thu Jul 25 06:21:51 2002
@@ -2,26 +2,30 @@
 
 # Define the host to be updated as 1st arguement to script
 if [ -z $1 ]; then
-	echo "Usage: ddupcron.sh hostname"
+	echo "Usage: ddupcron.sh hostname [interface]"
 	exit
 else
 	HOST=$1
 fi
 # Define interface to grep address from
-IFACE="eth0"
-IFCHECK=$(/sbin/ifconfig $IFACE|grep ask|awk '{print $2}'|cut -d ':' -f2)
+if [ -z $2 ]; then
+	IFACE=fxp0
+else
+	IFACE=$2
+fi
+IFCHECK=$(/sbin/ifconfig $IFACE|awk '/netmask/{print $2; exit}')
 # Define where we should store last IP
-IPFILE="/tmp/ddupip"
+IPFILE="/var/db/ddup.ip"
 IPCHECK=$(cat $IPFILE)
+FILECHECK=$(find $IPFILE -mtime -25)
+
 # Define path to ddup and ddup arguments (except --host)
-DDUP_PATH="/home/ddup/ddup"
+DDUP_PATH="%%PREFIX%%/sbin/ddup"
 DDUP_ARGS="--debug"
 
-
-if [ "$IFCHECK" = "$IPCHECK" ]; then
+if [ "$IFCHECK" = "$IPCHECK" ] && [ "x$FILECHECK" != x ]; then
 	echo "looks like we are still the same ip"
 else
 	$DDUP_PATH --host $HOST $DDUP_ARGS
 	echo "$IFCHECK" > $IPFILE
 fi
-
