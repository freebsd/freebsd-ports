--- src/DiskIO/Mmapped/MmappedFile.cc.orig	2023-02-28 09:10:25 UTC
+++ src/DiskIO/Mmapped/MmappedFile.cc
@@ -236,7 +236,7 @@ Mmapping::map()
     static const int pageSize = getpagesize();
     delta = offset % pageSize;
 
-    buf = mmap(nullptr, length + delta, prot, flags, fd, offset - delta);
+    buf = mmap(nullptr, length + delta, prot, flags | MAP_NOSYNC, fd, offset - delta);
 
     if (buf == MAP_FAILED) {
         const int errNo = errno;
