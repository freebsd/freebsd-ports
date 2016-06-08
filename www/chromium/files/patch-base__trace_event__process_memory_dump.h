--- base/trace_event/process_memory_dump.h.orig	2016-05-25 15:00:55.000000000 -0400
+++ base/trace_event/process_memory_dump.h	2016-05-27 01:46:53.167565000 -0400
@@ -23,7 +23,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if (defined(OS_POSIX) && !defined(OS_NACL)) || defined(OS_WIN)
+#if (defined(OS_POSIX) && !defined(OS_NACL) && !defined(OS_BSD)) || defined(OS_WIN)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
