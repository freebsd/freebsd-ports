--- src/regutf8.h.orig	Thu Sep 12 00:17:54 2002
+++ src/regutf8.h	Thu Sep 12 00:18:02 2002
@@ -19,7 +19,7 @@
 #endif
 
 #ifndef REG_OK
-#define REG_OK REG_NOERROR
+#define REG_OK 0
 #endif
 
 // ----------------------------------------------------------------------------
