--- vobcopy.h.orig	Mon Nov 13 19:57:24 2006
+++ vobcopy.h	Mon Dec  4 23:57:12 2006
@@ -19,7 +19,6 @@
 
 #if ( defined( __unix__ ) || defined( unix )) && !defined( USG )
 #include <sys/param.h>
-#else
 #endif
 
 #if defined( __GNUC__ ) && \
@@ -31,6 +30,8 @@
 /* by some bugreport:*/
 #if !( defined( BSD ) && ( BSD >= 199306 ) ) && !defined( sun )
 #include <stdint.h>
+#else
+#include <inttypes.h>
 #endif
 
 /*for/from play_title.c*/
@@ -66,24 +67,23 @@
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
@@ -170,7 +170,10 @@
 
 #include "dvd.h"
 
+/* BSD already have off_t definition */
+#if !(defined(BSD) && (BSD >= 199306))
 #define off_t __off64_t
+#endif
 
 void usage(char *);
 int add_end_slash( char * );
