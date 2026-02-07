--- error.h.orig	1997-06-30 03:11:54.000000000 +0000
+++ error.h
@@ -1,7 +1,7 @@
 #ifndef ERROR_H
 #define ERROR_H
 
-extern int errno;
+#include <errno.h>
 
 extern int error_intr;
 extern int error_nomem;
