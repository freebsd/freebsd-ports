--- dissipate2/extern_md5.h.orig	Mon Jul  5 14:01:05 2004
+++ dissipate2/extern_md5.h	Mon Jul  5 14:08:08 2004
@@ -1,6 +1,8 @@
 #ifndef EXTERN_MD5_H
 #define EXTERN_MD5_H
 
+#include <sys/types.h>
+
 #define HASHLEN 16
 typedef u_char HASH[HASHLEN];
 #define HASHHEXLEN 32
