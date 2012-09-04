--- deps/uv/include/uv-private/uv-bsd.h.orig	2012-09-03 09:42:53.000000000 +0800
+++ deps/uv/include/uv-private/uv-bsd.h	2012-09-03 09:43:18.000000000 +0800
@@ -23,7 +23,7 @@
 #define UV_BSD_H
 
 #define UV_PLATFORM_FS_EVENT_FIELDS                                           \
-  uv__io_t event_watcher;                                                     \
+  ev_io event_watcher;                                                     \
   int fflags;                                                                 \
   int fd;                                                                     \
 
