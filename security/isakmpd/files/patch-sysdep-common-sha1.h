--- sysdep/common/sha1.h.orig	Sun Jan 28 19:38:47 2001
+++ sysdep/common/sha1.h	Sat Sep 29 16:27:50 2007
@@ -6,13 +6,20 @@
 100% Public Domain
 */
 
+#include <sys/types.h>
+
+/* Check if already defined by md5.h */
+#ifndef PROTOTYPES
+typedef u_int32_t UINT4;
+#endif
+
 typedef struct {
-    unsigned long state[5];
-    unsigned long count[2];
+    UINT4 state[5];
+    UINT4 count[2];
     unsigned char buffer[64];
 } SHA1_CTX;
 
-void SHA1Transform(unsigned long state[5], unsigned char buffer[64]);
+void SHA1Transform(UINT4 state[5], unsigned char buffer[64]);
 void SHA1Init(SHA1_CTX* context);
 void SHA1Update(SHA1_CTX* context, unsigned char* data, unsigned int len);
 void SHA1Final(unsigned char digest[20], SHA1_CTX* context);
