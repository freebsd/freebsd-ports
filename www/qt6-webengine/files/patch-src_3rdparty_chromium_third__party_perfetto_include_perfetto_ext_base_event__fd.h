--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2022-02-07 13:39:41 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -55,6 +55,8 @@ class EventFd {
   // On Mac and other non-Linux UNIX platforms a pipe-based fallback is used.
   // The write end of the wakeup pipe.
   ScopedFile write_fd_;
+#else
+  ScopedFile write_fd_;
 #endif
 };
 
