--- nxviewer/nxviewer/misc.c.orig	Wed Nov 15 10:32:49 2006
+++ nxviewer/nxviewer/misc.c
@@ -337,6 +337,7 @@
     return (*defaultXErrorHandler)(dpy, error);
   }  
   nxviewerEnableSharedMemory = FALSE;
+  return 0;
 }
 
 static int
