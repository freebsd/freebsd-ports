diff -urN core/Utils.c core/Utils.c
--- core/Utils.c	Wed May 26 05:51:32 2004
+++ core/Utils.c	Fri Nov 19 08:08:07 2004
@@ -38,7 +38,7 @@
 {
 #if defined( HB_BEOS )
     snooze( time );
-#elif defined( HB_MACOSX ) || defined( HB_LINUX )
+#elif defined( HB_MACOSX ) || defined( HB_LINUX ) || defined( HB_FREEBSD )
     usleep( time );
 #elif defined( HB_CYGWIN )
     Sleep( time / 1000 );
