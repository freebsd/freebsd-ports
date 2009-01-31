--- src/extensions/inotify/fallback-inotify.h.orig	Sat Mar 10 11:49:38 2007
+++ src/extensions/inotify/fallback-inotify.h	Sat Mar 10 17:02:21 2007
@@ -7,7 +7,9 @@
 #ifndef _LINUX_INOTIFY_H
 #define _LINUX_INOTIFY_H
 
-#include <linux/types.h>
+#include <sys/types.h>
+typedef int		__s32;
+typedef unsigned int	__u32;
 
 /*
  * struct inotify_event - structure read from the inotify device for each event
