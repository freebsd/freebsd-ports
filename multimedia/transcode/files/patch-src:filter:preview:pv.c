--- filter/preview/pv.c.orig	Mon Nov  4 18:38:27 2002
+++ filter/preview/pv.c	Mon Nov  4 18:39:27 2002
@@ -38,7 +38,7 @@
 #include <sys/shm.h>
 
 #ifdef __FreeBSD__ /* We don't have on_exit() */
-dv_display_t 	*dv_dpy_on_exit_hack = NULL;
+xv_display_t 	*xv_dpy_on_exit_hack = NULL;
 #endif
 
 #define XV_FORMAT_MASK		0x03
@@ -128,7 +128,7 @@
   free(dv_dpy);
   dv_dpy = NULL;
 #ifdef __FreeBSD__
-  dv_dpy_on_exit_hack = NULL;
+  xv_dpy_on_exit_hack = NULL;
 #endif
 } // xv_display_exit
 
@@ -536,7 +536,7 @@
   }
   
 #ifdef __FreeBSD__
-  dv_dpy_on_exit_hack = dv_dpy;
+  xv_dpy_on_exit_hack = dv_dpy;
   atexit(xv_display_on_exit_hack_handler);
 #else
   on_exit(xv_display_exit_handler, dv_dpy);
