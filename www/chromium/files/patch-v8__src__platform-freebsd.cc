--- v8/src/platform-freebsd.cc.orig	2013-11-08 08:01:04.000000000 +0100
+++ v8/src/platform-freebsd.cc	2013-11-15 14:07:46.000000000 +0100
@@ -189,7 +189,7 @@
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == NULL) continue;
     buffer[bytes_read] = 0;
-    LOG(isolate SharedLibraryEvent(start_of_path, start, end));
+    LOG(isolate, SharedLibraryEvent(start_of_path, start, end));
   }
   close(fd);
 }
