--- src/peo/sha1.h.orig	Sun May 13 00:40:12 2001
+++ src/peo/sha1.h	Sun May 13 00:40:37 2001
@@ -9,7 +9,7 @@
 #ifndef _SHA1_H
 #define _SHA1_H
 
-#include "typedefs.h"
+#include <sys/types.h>
 
 typedef struct {
     u_int32_t state[5];
