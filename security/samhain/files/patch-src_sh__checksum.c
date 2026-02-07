--- src/sh_checksum.c.orig	2024-01-27 14:26:35 UTC
+++ src/sh_checksum.c
@@ -468,7 +468,7 @@ void SHA256_Final(sha2_byte digest[], SHA256_CTX* cont
       }
     }
 #else
-    memset(d, context->state, SHA256_DIGEST_LENGTH);
+    memcpy(d, context->state, SHA256_DIGEST_LENGTH);
     /* bcopy(context->state, d, SHA256_DIGEST_LENGTH); */
 #endif
   }
