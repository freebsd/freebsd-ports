--- ./v8/src/platform-freebsd.cc.orig	2014-08-20 21:04:33.000000000 +0200
+++ ./v8/src/platform-freebsd.cc	2014-08-22 18:16:57.000000000 +0200
@@ -130,14 +130,14 @@
     addr_buffer[0] = '0';
     addr_buffer[1] = 'x';
     addr_buffer[10] = 0;
-    int result = read(fd, addr_buffer + 2, 8);
-    if (result < 8) break;
+    int resultread = read(fd, addr_buffer + 2, 8);
+    if (resultread < 8) break;
     unsigned start = StringToLong(addr_buffer);
-    result = read(fd, addr_buffer + 2, 1);
-    if (result < 1) break;
+    resultread = read(fd, addr_buffer + 2, 1);
+    if (resultread < 1) break;
     if (addr_buffer[2] != '-') break;
-    result = read(fd, addr_buffer + 2, 8);
-    if (result < 8) break;
+    resultread = read(fd, addr_buffer + 2, 8);
+    if (resultread < 8) break;
     unsigned end = StringToLong(addr_buffer);
     char buffer[MAP_LENGTH];
     int bytes_read = -1;
@@ -145,8 +145,8 @@
       bytes_read++;
       if (bytes_read >= MAP_LENGTH - 1)
         break;
-      result = read(fd, buffer + bytes_read, 1);
-      if (result < 1) break;
+      resultread = read(fd, buffer + bytes_read, 1);
+      if (resultread < 1) break;
     } while (buffer[bytes_read] != '\n');
     buffer[bytes_read] = 0;
     // Ignore mappings that are not executable.
