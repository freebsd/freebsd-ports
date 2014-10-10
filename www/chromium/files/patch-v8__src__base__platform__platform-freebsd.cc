--- v8/src/base/platform/platform-freebsd.cc.orig	2014-10-02 17:41:11 UTC
+++ v8/src/base/platform/platform-freebsd.cc
@@ -131,14 +131,14 @@
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
@@ -146,8 +146,8 @@
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
