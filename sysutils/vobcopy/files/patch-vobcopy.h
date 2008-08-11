--- vobcopy.h.orig	2008-02-19 06:27:04.000000000 +0100
+++ vobcopy.h	2008-07-03 17:04:11.890928512 +0200
@@ -58,7 +58,7 @@
 /* //////////  *BSD //////////  */
 #if ( defined( BSD ) && ( BSD >= 199306 ) )

-#  if  !defined( __NetBSD__ ) ) || \
+#  if  ! ( defined( __NetBSD__ ) ) || \
        ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) )
 #include <sys/mount.h>
 #define USE_STATFS 1
@@ -87,12 +87,14 @@
 #define GETMNTINFO_USES_STATVFS

 #    endif
+#  endif

-#  else
-
+#if defined(__FreeBSD__)
+#define USE_STATFS_FOR_DEV
+#include <sys/statvfs.h>
+#else
 #include <sys/vfs.h>
-
-#  endif
+#endif

 #define HAS_LARGEFILE 1
