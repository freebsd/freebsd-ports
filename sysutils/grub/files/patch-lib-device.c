--- lib/device.c.orig	2008-12-09 22:44:39.000000000 +0100
+++ lib/device.c	2008-12-09 22:45:41.000000000 +0100
@@ -713,7 +713,7 @@
 #endif /* __linux__ */
     
   /* IDE disks.  */
-  for (i = 0; i < 8; i++)
+  for (i = 0; i < 20; i++)
     {
       char name[16];
       
