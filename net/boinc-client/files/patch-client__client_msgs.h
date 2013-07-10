--- client/client_msgs.h.old	2013-05-17 14:13:10.000000000 +0300
+++ client/client_msgs.h	2013-05-17 14:13:20.000000000 +0300
@@ -73,6 +73,6 @@
     __attribute__ ((format (printf, 4, 5)))
 ;
 
-#define _(x) "_(\""x"\")"
+#define _(x) "_(\"" x"\")"
 
 #endif
