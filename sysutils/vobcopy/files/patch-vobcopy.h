--- vobcopy.h.orig	Wed Dec  7 21:32:10 2005
+++ vobcopy.h	Sun Jan  8 15:26:43 2006
@@ -19,7 +19,6 @@
 
 #if ( defined( __unix__ ) || defined( unix )) && !defined( USG )
 #include <sys/param.h>
-#else
 #endif
 
 #if defined( __GNUC__ ) && \
@@ -32,6 +31,8 @@
 /* by some bugreport:*/
 #if !( defined( BSD ) && ( BSD >= 199306 ) ) && !defined( sun )
 #include <stdint.h>
+#else
+#include <inttypes.h>
 #endif
 
 /*for/from play_title.c*/
@@ -67,24 +68,23 @@
 /* //////////  *BSD //////////  */
 #if ( defined( BSD ) && ( BSD >= 199306 ) )
 
-#  if  !defined( __NetBSD__ ) ) || \
-       ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) )
-#include <sys/mount.h>
-#define USE_STATFS 1
+#  if ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) ) || \
+      ( defined( __FreeBSD__) && ( __FreeBSD_version >= 500040 ) )
+#include <sys/statvfs.h>
 
 #  else
 
-#include <sys/statvfs.h>
+#include <sys/mount.h>
+#define USE_STATFS 1
 
 #  endif
 
-#  if defined(NetBSD)
-
-#include <sys/param.h>
+#  if defined(__NetBSD__) || defined(__FreeBSD__)
 
 #define USE_GETMNTINFO
 
-#    if ( __NetBSD_Version__ < 200040000 )
+#    if (defined( __NetBSD__ ) && ( __NetBSD_Version__ < 200040000 )) || \
+        (defined( __FreeBSD__ ))
 
 #include <sys/mount.h>
 #define USE_STATFS_FOR_DEV
