--- ./base/files/file_path_watcher_kqueue.h.orig	2014-08-20 21:02:41.000000000 +0200
+++ ./base/files/file_path_watcher_kqueue.h	2014-08-23 19:32:36.000000000 +0200
@@ -5,6 +5,10 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#ifdef __FreeBSD__
+#include <sys/stdint.h>
+#include <sys/types.h>
+#endif
 #include <sys/event.h>
 #include <vector>
 
