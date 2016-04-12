--- base/trace_event/process_memory_dump.cc.orig	2016-03-05 15:21:43.755196423 +0100
+++ base/trace_event/process_memory_dump.cc	2016-03-05 15:22:37.112362644 +0100
@@ -66,7 +66,7 @@
     int error_counter = 0;
     // HANDLE_EINTR tries for 100 times. So following the same pattern.
     do {
-      result = mincore(chunk_start, chunk_size, vec.data());
+      result = mincore(chunk_start, chunk_size, (char *) vec.data());
     } while (result == -1 && errno == EAGAIN && error_counter++ < 100);
     if (result)
       break;
