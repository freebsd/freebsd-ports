--- motsognir.c.orig	2019-07-07 18:44:09.203615614 +0000
+++ motsognir.c	2020-05-26 12:57:14.435049000 +0000
@@ -59,6 +59,10 @@
   #define CONFIGFILE "/etc/motsognir.conf"
 #endif
 
+/* in FreeBSD there is no MSG_MORE by default */
+#ifndef MSG_MORE
+  #define MSG_MORE 0
+#endif
 
 #define CFG_SUBGOPHERMAPS 1
 #define CFG_CAPSSUPPORT   2
