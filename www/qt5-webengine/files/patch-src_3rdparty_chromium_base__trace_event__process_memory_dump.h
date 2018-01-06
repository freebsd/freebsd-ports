--- src/3rdparty/chromium/base/trace_event/process_memory_dump.h.orig	2017-01-26 00:49:07 UTC
+++ src/3rdparty/chromium/base/trace_event/process_memory_dump.h
@@ -24,7 +24,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if (defined(OS_POSIX) && !defined(OS_NACL)) || defined(OS_WIN)
+#if (defined(OS_POSIX) && !defined(OS_NACL) && !defined(OS_BSD)) || defined(OS_WIN)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
