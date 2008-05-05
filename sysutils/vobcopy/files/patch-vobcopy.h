-- vobcopy.h.orig       2008-04-13 14:01:03.000000000 +0000
+++ vobcopy.h   2008-04-13 14:08:18.000000000 +0000
@@ -58,7 +58,7 @@
 /* //////////  *BSD //////////  */
 #if ( defined( BSD ) && ( BSD >= 199306 ) )

-#  if  !defined( __NetBSD__ ) ) || \
+#  if  ! ( defined( __NetBSD__ ) ) || \
        ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) )
 #include <sys/mount.h>
 #define USE_STATFS 1
@@ -87,12 +87,13 @@
 #define GETMNTINFO_USES_STATVFS

 #    endif
+#  endif

-#  else
-
+#if defined(__FreeBSD__)
+#include <sys/statvfs.h>
+#else
 #include <sys/vfs.h>
-
-#  endif
+#endif

 #define HAS_LARGEFILE 1
