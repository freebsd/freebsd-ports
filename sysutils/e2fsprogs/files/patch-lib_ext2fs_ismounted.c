--- a/lib/ext2fs/ismounted.c.orig	Tue Apr 10 23:38:42 2007
+++ b/lib/ext2fs/ismounted.c	Tue Apr 10 23:41:32 2007
@@ -325,9 +325,9 @@
 			*mount_flags |= EXT2_MF_BUSY;
 	} else
 		close(fd);
+#endif
 
 	return 0;
-#endif
 }
 
 /*
