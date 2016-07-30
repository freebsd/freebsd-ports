--- lib/blkdev.c.orig	2016-07-30 07:16:42 UTC
+++ lib/blkdev.c
@@ -133,7 +133,7 @@ blkdev_get_size(int fd, unsigned long lo
 	}
 #endif /* FDGETPRM */
 
-#ifdef HAVE_SYS_DISKLABEL_H
+#if defined(HAVE_SYS_DISKLABEL_H) && defined(DIOCGDINFO)
 	{
 		/*
 		 * This code works for FreeBSD 4.11 i386, except for the full device
@@ -161,7 +161,7 @@ blkdev_get_size(int fd, unsigned long lo
 			}
 		}
 	}
-#endif /* HAVE_SYS_DISKLABEL_H */
+#endif /* defined(HAVE_SYS_DISKLABEL_H) && defined(DIOCGDINFO) */
 
 	{
 		struct stat st;
