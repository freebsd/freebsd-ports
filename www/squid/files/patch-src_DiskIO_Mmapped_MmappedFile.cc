--- src/DiskIO/Mmapped/MmappedFile.cc.orig	2015-04-15 10:39:56.146312000 +0300
+++ src/DiskIO/Mmapped/MmappedFile.cc	2015-04-15 10:40:53.487834000 +0300
@@ -235,7 +235,7 @@
     static const int pageSize = getpagesize();
     delta = offset % pageSize;
 
-    buf = mmap(NULL, length + delta, prot, flags, fd, offset - delta);
+    buf = mmap(NULL, length + delta, prot, flags | MAP_NOSYNC, fd, offset - delta);
 
     if (buf == MAP_FAILED) {
         const int errNo = errno;
