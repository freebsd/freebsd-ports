--- quicktime/qtprivate.h.orig	Mon Feb 12 22:35:19 2001
+++ quicktime/qtprivate.h	Mon Nov  1 09:41:06 2004
@@ -13,8 +13,8 @@
 typedef int64_t longest;
 typedef u_int64_t ulongest;
 
-#define FTELL ftello64
-#define FSEEK fseeko64
+#define FTELL ftello
+#define FSEEK fseeko
 
 typedef struct
 {
