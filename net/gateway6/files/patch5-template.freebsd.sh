--- template/freebsd.sh.orig	2005-10-25 20:38:02.000000000 +0200
+++ template/freebsd.sh	2007-07-11 23:33:20.000000000 +0200
@@ -76,7 +76,7 @@
 Display 1 '--- Start of configuration script. ---'
 Display 1 "Script: " `basename $0`
 
-gifconfig=/usr/sbin/gifconfig
+gifconfig=/sbin/ifconfig
 ifconfig=/sbin/ifconfig
 route=/sbin/route
 rtadvd=/usr/sbin/rtadvd
