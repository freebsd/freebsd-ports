--- fs/native.cpp.orig	2016-03-09 02:07:44 UTC
+++ fs/native.cpp
@@ -84,8 +84,7 @@ void preAllocateSpaceBestEffort(FileHand
 
 #elif defined ZEN_LINUX
     //don't use potentially inefficient ::posix_fallocate!
-    const int rv = ::fallocate(fh,          //int fd,
-                               0,           //int mode,
+    const int rv = ::posix_fallocate(fh,          //int fd,
                                0,           //off_t offset
                                streamSize); //off_t len
     if (rv != 0)
