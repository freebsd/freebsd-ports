--- ./parser.y.orig	2014-08-01 13:12:16.000000000 -0400
+++ ./parser.y	2014-08-01 13:12:32.000000000 -0400
@@ -32,6 +32,7 @@
  * $FreeBSD: src/usr.sbin/bluetooth/bthidd/parser.y,v 1.4.2.2 2006/12/01 23:33:22 emax Exp $
  */
 
+#include <stdlib.h>
 #include <sys/queue.h>
 #include <bluetooth.h>
 #include <dev/usb/usb.h>
