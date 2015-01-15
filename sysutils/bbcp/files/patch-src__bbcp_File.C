--- src/bbcp_File.C.orig	2015-01-14 12:12:57.000000000 -0800
+++ src/bbcp_File.C	2015-01-14 12:24:35.000000000 -0800
@@ -44,7 +44,7 @@
 
 #ifdef FREEBSD
 #undef ENODATA
-#define ENODATA ENOATTRR
+#define ENODATA ENOATTR
 #endif
 
 /******************************************************************************/
