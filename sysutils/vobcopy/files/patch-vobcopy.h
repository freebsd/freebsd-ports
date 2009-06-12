--- vobcopy.h.old	2009-06-12 10:46:16.000000000 +0000
+++ vobcopy.h	2009-06-12 10:47:20.000000000 +0000
@@ -69,7 +69,7 @@
 /* //////////  *BSD //////////  */
 #if ( defined( BSD ) && ( BSD >= 199306 ) )
 
-#if !defined( __NetBSD__ ) || \
+#if  ! ( defined( __NetBSD__ ) ) || \
        ( defined( __NetBSD__) && ( __NetBSD_Version__ < 200040000 ) )
 #include <sys/mount.h>
 #define USE_STATFS 1
