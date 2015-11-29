--- src/DiskIO/Mmapped/MmappedFile.cc.orig	2015-11-01 10:44:25 UTC
+++ src/DiskIO/Mmapped/MmappedFile.cc
@@ -235,7 +235,7 @@ Mmapping::map()
     static const int pageSize = getpagesize();
     delta = offset % pageSize;
 
-    buf = mmap(NULL, length + delta, prot, flags, fd, offset - delta);
+    buf = mmap(NULL, length + delta, prot, flags | MAP_NOSYNC, fd, offset - delta);
 
     if (buf == MAP_FAILED) {
         const int errNo = errno;
