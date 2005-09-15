--- C/load_aout.c.orig	Thu Sep 15 09:59:51 2005
+++ C/load_aout.c	Thu Sep 15 10:04:05 2005
@@ -43,6 +43,8 @@
 #endif
 #include <a.out.h>
 
+#define YAP_FILE_MAX PATH_MAX
+
 static char YapExecutable[YAP_FILE_MAX];
 
 #define oktox(n) \
