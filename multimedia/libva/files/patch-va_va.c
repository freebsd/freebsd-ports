--- va/va.c.orig	2017-10-21 04:49:28 UTC
+++ va/va.c
@@ -350,7 +350,7 @@ static VAStatus va_openDriver(VADisplay dpy, char *dri
         strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );
         
         va_infoMessage(dpy, "Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#if !defined(ANDROID) && defined(RTLD_NODELETE)
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
