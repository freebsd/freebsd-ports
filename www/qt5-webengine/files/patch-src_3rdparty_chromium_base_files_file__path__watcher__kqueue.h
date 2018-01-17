--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/files/file_path_watcher_kqueue.h
@@ -5,6 +5,10 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#ifdef __FreeBSD__
+#include <sys/stdint.h>
+#include <sys/types.h>
+#endif
 #include <sys/event.h>
 
 #include <memory>
