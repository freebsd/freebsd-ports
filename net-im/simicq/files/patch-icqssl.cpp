
--- sim/libicq/icqssl.cpp.orig	Wed Mar 12 14:20:53 2003
+++ sim/libicq/icqssl.cpp	Wed Mar 12 14:21:08 2003
@@ -151,7 +151,7 @@
 #else
         SSL_CTX_set_cipher_list(gSSL_CTX, "ADH");
 #endif
-        SSL_CTX_set_info_callback(gSSL_CTX, (void (*)())ssl_info_callback);
+        SSL_CTX_set_info_callback(gSSL_CTX, (void (*)(const SSL*, int, int))ssl_info_callback);
         DH *dh = get_dh512();
         SSL_CTX_set_tmp_dh(gSSL_CTX, dh);
         DH_free(dh);
	


