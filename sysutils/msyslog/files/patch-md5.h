--- src/peo/md5.h.orig	Tue Dec  5 00:17:51 2000
+++ src/peo/md5.h	Sun May 13 00:38:59 2001
@@ -27,7 +27,7 @@
 #ifndef _MD5_H_
 #define _MD5_H_
 
-#include "typedefs.h"
+#include <sys/types.h>
 
 /* MD5 context. */
 typedef struct MD5Context {
