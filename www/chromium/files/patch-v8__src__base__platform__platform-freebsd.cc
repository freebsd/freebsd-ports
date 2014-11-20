--- v8/src/base/platform/platform-freebsd.cc.orig	2014-10-17 02:58:15.000000000 +0200
+++ v8/src/base/platform/platform-freebsd.cc	2014-10-20 18:26:17.000000000 +0200
@@ -141,21 +141,21 @@
     if (bytes_read < 8) break;
     unsigned end = StringToLong(addr_buffer);
     char buffer[MAP_LENGTH];
-    int bytes_read = -1;
+    int _bytes_read = -1;
     do {
-      bytes_read++;
-      if (bytes_read >= MAP_LENGTH - 1)
+      _bytes_read++;
+      if (_bytes_read >= MAP_LENGTH - 1)
         break;
-      bytes_read = read(fd, buffer + bytes_read, 1);
+      bytes_read = read(fd, buffer + _bytes_read, 1);
       if (bytes_read < 1) break;
-    } while (buffer[bytes_read] != '\n');
-    buffer[bytes_read] = 0;
+    } while (buffer[_bytes_read] != '\n');
+    buffer[_bytes_read] = 0;
     // Ignore mappings that are not executable.
     if (buffer[3] != 'x') continue;
     char* start_of_path = index(buffer, '/');
     // There may be no filename in this line.  Skip to next.
     if (start_of_path == NULL) continue;
-    buffer[bytes_read] = 0;
+    buffer[_bytes_read] = 0;
     result.push_back(SharedLibraryAddress(start_of_path, start, end));
   }
   close(fd);
@@ -187,7 +187,7 @@
   void* reservation = mmap(OS::GetRandomMmapAddr(),
                            request_size,
                            PROT_NONE,
-                           MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                           MAP_PRIVATE | MAP_ANON,
                            kMmapFd,
                            kMmapFdOffset);
   if (reservation == MAP_FAILED) return;
@@ -259,7 +259,7 @@
   void* result = mmap(OS::GetRandomMmapAddr(),
                       size,
                       PROT_NONE,
-                      MAP_PRIVATE | MAP_ANON | MAP_NORESERVE,
+                      MAP_PRIVATE | MAP_ANON,
                       kMmapFd,
                       kMmapFdOffset);
 
@@ -287,7 +287,7 @@
   return mmap(base,
               size,
               PROT_NONE,
-              MAP_PRIVATE | MAP_ANON | MAP_NORESERVE | MAP_FIXED,
+              MAP_PRIVATE | MAP_ANON | MAP_FIXED,
               kMmapFd,
               kMmapFdOffset) != MAP_FAILED;
 }
