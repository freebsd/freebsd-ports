--- src/libaudcore/vfs.h.orig	2023-04-29 20:10:24 UTC
+++ src/libaudcore/vfs.h
@@ -51,6 +51,7 @@ enum VFSSeekType
 
 enum VFSSeekType
 {
+    VFS_SEEK_UNK = -1,
     VFS_SEEK_SET = 0,
     VFS_SEEK_CUR = 1,
     VFS_SEEK_END = 2
