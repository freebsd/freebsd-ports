--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/event_fd.h
@@ -58,6 +58,8 @@ class EventFd {
   // On Mac and other non-Linux UNIX platforms a pipe-based fallback is used.
   // The write end of the wakeup pipe.
   ScopedFile write_fd_;
+#else
+  ScopedFile write_fd_;
 #endif
 };
 
