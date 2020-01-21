--- interface/ztrmv.c.orig	2019-04-29 17:22:19 UTC
+++ interface/ztrmv.c
@@ -245,7 +245,7 @@ void CNAME(enum CBLAS_ORDER order, enum CBLAS_UPLO Upl
   else
 #endif
   {
-    buffer_size = ((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT);
+    buffer_size = (((n - 1) / DTB_ENTRIES) * 2 * DTB_ENTRIES + 32 / sizeof(FLOAT)) + 8;
     // It seems to be required for some K8 or Barcelona CPU
     buffer_size += 8;
     if(incx != 1)
