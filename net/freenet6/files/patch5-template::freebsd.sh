--- template/freebsd.sh.orig	Fri Jun 11 12:41:18 2004
+++ template/freebsd.sh	Sat Nov 20 14:56:36 2004
@@ -80,7 +80,7 @@
 Display 1 '--- Start of configuration script. ---'
 Display 1 "Script: " `basename $0`
 
-gifconfig=/usr/sbin/gifconfig
+gifconfig=/usr/sbin/ifconfig
 ifconfig=/sbin/ifconfig
 route=/sbin/route
 rtadvd=/usr/sbin/rtadvd
