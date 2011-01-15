--- va/va.c~
+++ va/va.c
@@ -199,7 +199,7 @@ static VAStatus va_openDriver(VADisplay 
         strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );
         
         va_infoMessage("Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#if !defined(ANDROID) && defined(RTLD_NODELETE)
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
