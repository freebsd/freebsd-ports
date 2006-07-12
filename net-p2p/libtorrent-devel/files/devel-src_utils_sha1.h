--- src/utils/sha1.h.orig	Wed Jul 12 11:35:43 2006
+++ src/utils/sha1.h	Wed Jul 12 11:36:04 2006
@@ -87,7 +87,7 @@
 Sha1::final_c(char* buffer) {
   unsigned int len;
   
-  SHA1_End(&m_ctx, buffer, &len, 20);
+  SHA1_End(&m_ctx, (unsigned char*)buffer, &len, 20);
 }
 
 #elif defined USE_OPENSSL_SHA
