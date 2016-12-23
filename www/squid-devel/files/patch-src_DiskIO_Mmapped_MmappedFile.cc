--- src/DiskIO/Mmapped/MmappedFile.cc.orig	2016-12-16 10:06:20 UTC
+++ src/DiskIO/Mmapped/MmappedFile.cc
@@ -236,7 +236,7 @@ Mmapping::map()
     static const int pageSize = getpagesize();
     delta = offset % pageSize;
 
-    buf = mmap(NULL, length + delta, prot, flags, fd, offset - delta);
+    buf = mmap(NULL, length + delta, prot, flags | MAP_NOSYNC, fd, offset - delta);
 
     if (buf == MAP_FAILED) {
         const int errNo = errno;
