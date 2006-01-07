--- vobcopy.h.orig	Fri Jan  6 23:22:11 2006
+++ vobcopy.h	Fri Jan  6 23:34:11 2006
@@ -67,24 +67,33 @@
 /* //////////  *BSD //////////  */
 #if ( defined( BSD ) && ( BSD >= 199306 ) )
 
-#  if  !defined( __NetBSD__ ) ) || \
-       ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) )
-#include <sys/mount.h>
-#define USE_STATFS 1
+#  if ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) ) || \
+      ( defined( __FreeBSD__) && \
+	( ((__FreeBSD_version >= 460102 ) && (__FreeBSD_version < 500000)) || \
+	  ( __FreeBSD_version >= 500040) \
+	) \
+      )
+#include <sys/statvfs.h>
 
 #  else
 
-#include <sys/statvfs.h>
+#include <sys/mount.h>
+#define USE_STATFS 1
 
 #  endif
 
-#  if defined(NetBSD)
+#  if defined(__NetBSD__) || defined(__FreeBSD__)
 
 #include <sys/param.h>
 
 #define USE_GETMNTINFO
 
-#    if ( __NetBSD_Version__ < 200040000 )
+#    if (defined( __NetBSD__ ) && ( __NetBSD_Version__ < 200040000 )) || \
+        ( defined( __FreeBSD__) && \
+	  ( ((__FreeBSD_version >= 460102 ) && (__FreeBSD_version < 500000)) || \
+	    ( __FreeBSD_version >= 500040) \
+	  ) \
+	)
 
 #include <sys/mount.h>
 #define USE_STATFS_FOR_DEV
