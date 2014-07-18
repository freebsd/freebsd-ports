--- ./va/va.c.orig	2014-05-09 12:38:02.000000000 +0800
+++ ./va/va.c	2014-07-17 19:11:43.977174636 +0800
@@ -227,7 +227,7 @@
         strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );
         
         va_infoMessage("Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#if !defined(ANDROID) && defined(RTLD_NODELETE)
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
@@ -515,15 +515,15 @@
   free(old_ctx->vtable_vpp);
   old_ctx->vtable_vpp = NULL;
 
-  if (VA_STATUS_SUCCESS == vaStatus)
-      pDisplayContext->vaDestroy(pDisplayContext);
-
   VA_TRACE_LOG(va_TraceTerminate, dpy);
 
   va_TraceEnd(dpy);
 
   va_FoolEnd(dpy);
 
+  if (VA_STATUS_SUCCESS == vaStatus)
+      pDisplayContext->vaDestroy(pDisplayContext);
+
   return vaStatus;
 }
 
