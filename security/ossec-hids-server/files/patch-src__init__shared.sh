--- ./src/init/shared.sh.orig	2013-10-29 12:13:44.000000000 -0600
+++ ./src/init/shared.sh	2014-04-21 19:52:35.000000000 -0600
@@ -28,7 +28,6 @@
 NAMESERVERS=`cat /etc/resolv.conf | grep "^nameserver" | cut -d " " -sf 2`
 NAMESERVERS2=`cat /etc/resolv.conf | grep "^nameserver" | cut -sf 2`
 HOST_CMD=`which host`
-CC=""
 NAME="OSSEC HIDS"
 INSTYPE="server"
 DEFAULT_DIR=`grep DIR ${LOCATION} | cut -f2 -d\"`
