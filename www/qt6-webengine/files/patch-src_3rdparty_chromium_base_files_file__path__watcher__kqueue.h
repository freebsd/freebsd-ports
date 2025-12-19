--- src/3rdparty/chromium/base/files/file_path_watcher_kqueue.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/base/files/file_path_watcher_kqueue.h
@@ -5,6 +5,7 @@
 #ifndef BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 #define BASE_FILES_FILE_PATH_WATCHER_KQUEUE_H_
 
+#include <sys/time.h>
 #include <sys/event.h>
 
 #include <memory>
