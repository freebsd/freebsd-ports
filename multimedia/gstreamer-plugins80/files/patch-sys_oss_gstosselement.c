--- sys/oss/gstosselement.c.orig	Tue Apr  6 23:48:29 2004
+++ sys/oss/gstosselement.c	Tue Apr  6 23:48:42 2004
@@ -194,7 +194,7 @@
     goto end;
   }
 
-  if (lstat (device, &s) || !S_ISCHR (s.st_mode))
+  if (stat (device, &s) || !S_ISCHR (s.st_mode))
     goto end;
 
   *name = device;
