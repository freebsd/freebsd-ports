--- deps/v8/src/platform-freebsd.orig 2013-11-18 22:50:13.000000000 -0200
+++ deps/v8/src/platform-freebsd.cc 2013-11-18 22:55:37.000000000 -0200
@@ -189,7 +189,7 @@
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == NULL) continue;
     buffer[bytes_read] = 0;
-    LOG(isolate SharedLibraryEvent(start_of_path, start, end));
+    LOG(isolate, SharedLibraryEvent(start_of_path, start, end));
   }
   close(fd);
 }
