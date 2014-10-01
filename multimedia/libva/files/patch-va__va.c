--- va/va.c.orig	2014-09-30 01:48:34 UTC
+++ va/va.c
@@ -227,7 +227,7 @@
         strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );
         
         va_infoMessage("Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#if !defined(ANDROID) && defined(RTLD_NODELETE)
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
