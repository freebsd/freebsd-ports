--- base/trace_event/process_memory_dump.h.orig	2018-08-01 00:08:26.000000000 +0200
+++ base/trace_event/process_memory_dump.h	2018-08-04 13:49:22.487126000 +0200
@@ -22,7 +22,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
