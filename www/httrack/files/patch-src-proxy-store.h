--- src/proxy/store.h.orig	Sat Jul 29 00:15:48 2006
+++ src/proxy/store.h	Sat Jul 29 00:19:03 2006
@@ -28,6 +28,8 @@
 #ifndef WEBHTTRACK_PROXYTRACK_STORE
 #define WEBHTTRACK_PROXYTRACK_STORE

+#include <pthread.h>
+
 /* Proxy */

 typedef struct _PT_Index _PT_Index;
