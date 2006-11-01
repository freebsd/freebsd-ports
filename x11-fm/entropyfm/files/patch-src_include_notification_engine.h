--- src/include/notification_engine.h.orig	Tue Oct 17 21:24:21 2006
+++ src/include/notification_engine.h	Tue Oct 17 21:24:54 2006
@@ -1,6 +1,9 @@
 #ifndef __NOTIFICATION_ENGINE_H_
 #define __NOTIFICATION_ENGINE_H_
 
+#include <sys/types.h>
+#include <pthread.h>
+
 enum ENTROPY_NOTIFY_TYPES {
 	ENTROPY_NOTIFY_GENERIC = 0,
 	ENTROPY_NOTIFY_THUMBNAIL_REQUEST =1,
