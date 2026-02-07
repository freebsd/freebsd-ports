--- examples/bsd/vip-up.sh.orig	2006-05-27 20:38:34.000000000 +0000
+++ examples/bsd/vip-up.sh	2010-05-30 20:40:19.000000000 +0000
@@ -1,4 +1,21 @@
 #! /bin/sh
+
+if [ -z "$1" -o -z "$2" ]; then
+	cat <<EOF
+Usage: ${0##*/} interface virtual-address [if-keep-ip]
+  interface        - interface name where virtual IP-address to be assigned;
+  virtual-address  - virtual IP-address;
+  if-keep-ip       - interface name where virtual IP-address should be kept
+                     when ucarp changes state to BACKUP;
+
+EOF
+	exit 255
+fi
+
 exec 2> /dev/null
 
+if [ ! -z "$3" ]; then
+	/sbin/ifconfig "$3" -alias "$2"
+fi
+
 /sbin/ifconfig "$1" alias "$2" netmask 255.255.255.255
