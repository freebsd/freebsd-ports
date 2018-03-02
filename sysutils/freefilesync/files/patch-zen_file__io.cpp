--- ../../zen/file_io.cpp.orig	2018-03-01 11:10:56.764684000 +0200
+++ ../../zen/file_io.cpp	2018-03-01 11:12:35.599889000 +0200
@@ -305,8 +305,7 @@
 {
     const FileHandle fh = getHandle();
     //don't use potentially inefficient ::posix_fallocate!
-    const int rv = ::fallocate(fh,            //int fd,
-                               0,             //int mode,
+    const int rv = ::posix_fallocate(fh,            //int fd,
                                0,             //off_t offset
                                expectedSize); //off_t len
     if (rv != 0)
