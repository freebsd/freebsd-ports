--- src/gentoo.h.orig	Thu Aug 29 14:36:02 2002
+++ src/gentoo.h	Thu Aug 29 14:36:33 2002
@@ -443,7 +443,7 @@
 	gboolean	valid;			/* Set if the structure's contents are valid. */
 #if defined HAVE_STRUCT_STATVFS
 	struct statvfs	stat;			/* Holds information about filesystem. */
-#elif defined HAVE_STRUCT_STATFS
+#elif defined HAVE_STRUCT_STATFS || defined __FreeBSD__
 	struct statfs	stat;
 #endif
 } FsInfo;
