--- stage2/fsys_reiserfs.c.orig	Tue Jan  6 11:05:27 2004
+++ stage2/fsys_reiserfs.c	Tue Jan  6 11:05:59 2004
@@ -112,7 +112,7 @@
   /* offset in the log of where to start replay after a crash */
   __u32 j_first_unflushed_offset;
   /* mount id to detect very old transactions */
-  __u32 long j_mount_id;
+  __u64 j_mount_id;
 };

 /* magic string to find desc blocks in the journal */
