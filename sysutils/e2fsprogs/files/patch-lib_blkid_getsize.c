--- lib/blkid/getsize.c.orig	2014-08-02 20:26:22 UTC
+++ lib/blkid/getsize.c
@@ -127,7 +127,7 @@ blkid_loff_t blkid_get_dev_size(int fd)
 			return (blkid_loff_t)this_floppy.size << 9;
 	}
 #endif
-#ifdef HAVE_SYS_DISKLABEL_H
+#if defined(HAVE_SYS_DISKLABEL_H) && defined(DIOCGDINFO)
 	{
 		int part = -1;
 		struct disklabel lab;
@@ -154,7 +154,7 @@ blkid_loff_t blkid_get_dev_size(int fd)
 				return pp->p_size << 9;
 		}
 	}
-#endif /* HAVE_SYS_DISKLABEL_H */
+#endif /* defined(HAVE_SYS_DISKLABEL_H) && defined(DIOCGDINFO) */
 	{
 #if defined(HAVE_FSTAT64) && !defined(__OSX_AVAILABLE_BUT_DEPRECATED)
 		struct stat64   st;
