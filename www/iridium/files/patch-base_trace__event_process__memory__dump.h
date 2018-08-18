--- base/trace_event/process_memory_dump.h.orig	2018-05-09 21:05:33.000000000 +0200
+++ base/trace_event/process_memory_dump.h	2018-08-16 02:49:06.092591000 +0200
@@ -22,7 +22,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if (defined(OS_POSIX) && !defined(OS_NACL)) || defined(OS_WIN)
+#if (defined(OS_POSIX) && !defined(OS_NACL) && !defined(OS_BSD)) || defined(OS_WIN)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
