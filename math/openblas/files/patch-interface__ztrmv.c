--- interface/ztrmv.c.orig	2016-04-12 12:29:19.000000000 -0700
+++ interface/ztrmv.c	2016-06-08 16:44:31.800058000 -0700
@@ -242,7 +242,7 @@
   else
 #endif
   {
-    buffer_size = ((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT);
+    buffer_size = (((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT)) + 8;
     if(incx != 1)
       buffer_size += n * 2;
   }
