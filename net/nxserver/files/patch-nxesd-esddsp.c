--- nxesd/esddsp.c.orig	Wed May 25 17:40:19 2005
+++ nxesd/esddsp.c
@@ -227,7 +227,7 @@
   dsp_init ();
 
   va_start (args, flags);
-  mode = va_arg (args, mode_t);
+  mode = va_arg (args, int);
   va_end (args);
 
   if (!strcmp (pathname, "/dev/dsp"))
