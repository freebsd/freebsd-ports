--- file.cc.orig	2014-12-16 20:32:29.000000000 +0800
+++ file.cc	2015-06-23 13:16:37.741129000 +0800
@@ -6,7 +6,7 @@
 #include <unistd.h>
 #include <cerrno>
 #include <cstring>
-#ifdef __APPLE__
+#if defined(__APPLE_) || defined(__FreeBSD__)
   #include <sys/socket.h>
 #else
   #include <sys/sendfile.h>
@@ -67,6 +67,9 @@
       #ifdef __APPLE__
       if ( -1 == sendfile(write_fd, read_fd, offset, &stat_buf.st_size, NULL, 0) )
          throw exCantRename( from + " to " + to );
+      #elif defined(__FreeBSD__)
+      if ( -1 == sendfile(write_fd, read_fd, offset, stat_buf.st_size, NULL, NULL, 0) )
+         throw exCantRename( from + " to " + to );
       #else
       if ( -1 == sendfile(write_fd, read_fd, &offset, stat_buf.st_size) )
          throw exCantRename( from + " to " + to );
