--- ./client/client_msgs.h.orig	2013-07-24 15:13:28.000000000 +0000
+++ ./client/client_msgs.h	2013-09-17 21:16:00.000000000 +0000
@@ -73,6 +73,6 @@
     __attribute__ ((format (printf, 4, 5)))
 ;
 
-#define _(x) "_(\""x"\")"
+#define _(x) "_(\"" x"\")"
 
 #endif
