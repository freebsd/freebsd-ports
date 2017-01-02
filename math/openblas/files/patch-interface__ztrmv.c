--- interface/ztrmv.c.orig	2016-08-31 20:58:42.000000000 -0700
+++ interface/ztrmv.c	2017-01-01 10:26:22.759442000 -0800
@@ -242,7 +242,7 @@
   else
 #endif
   {
-    buffer_size = ((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT);
+    buffer_size = (((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT)) + 8;
     // It seems to be required for some K8 or Barcelona CPU
     buffer_size += 8;
     if(incx != 1)
