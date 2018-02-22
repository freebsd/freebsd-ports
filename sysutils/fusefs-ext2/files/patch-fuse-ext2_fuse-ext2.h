--- fuse-ext2/fuse-ext2.h.orig	2018-02-08 17:53:26 UTC
+++ fuse-ext2/fuse-ext2.h
@@ -34,6 +34,10 @@
 #include <fuse.h>
 #include <ext2fs/ext2fs.h>
 
+#ifndef ENODATA
+#define ENODATA ENOMSG
+#endif
+
 #if !defined(FUSE_VERSION) || (FUSE_VERSION < 26)
 #error "***********************************************************"
 #error "*                                                         *"
