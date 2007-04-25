--- src/ntfs-3g.c.orig	Thu Apr 26 01:51:08 2007
+++ src/ntfs-3g.c	Thu Apr 26 01:51:15 2007
@@ -134,7 +134,7 @@
 } opts;
 
 static const char *EXEC_NAME = "ntfs-3g";
-static char def_opts[] = "silent,allow_other,nonempty,";
+static char def_opts[] = "silent,allow_other,";
 static ntfs_fuse_context_t *ctx;
 static u32 ntfs_sequence;
 
