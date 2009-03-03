--- util/util_compat.h.orig	2009-03-03 13:18:33.000000000 +0100
+++ util/util_compat.h	2009-03-03 13:18:38.000000000 +0100
@@ -100,6 +100,10 @@
 };
 #endif /* NO_SOCKADDR_STORAGE */
 
+#ifndef SSL_OP_NO_TICKET 
+#define SSL_OP_NO_TICKET		0x00004000L
+#endif
+
 #ifdef __cplusplus
 }
 #endif
