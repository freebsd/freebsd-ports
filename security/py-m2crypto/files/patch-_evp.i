--- _evp.i.orig	Tue Mar 27 12:13:08 2001
+++ _evp.i	Tue Mar 27 12:13:13 2001
@@ -36,10 +36,6 @@
 %name(bf_cbc) extern EVP_CIPHER *EVP_bf_cbc(void);
 %name(bf_cfb) extern EVP_CIPHER *EVP_bf_cfb(void);
 %name(bf_ofb) extern EVP_CIPHER *EVP_bf_ofb(void);
-%name(idea_ecb) extern EVP_CIPHER *EVP_idea_ecb(void);
-%name(idea_cbc) extern EVP_CIPHER *EVP_idea_cbc(void);
-%name(idea_cfb) extern EVP_CIPHER *EVP_idea_cfb(void);
-%name(idea_ofb) extern EVP_CIPHER *EVP_idea_ofb(void);
 %name(cast5_ecb) extern EVP_CIPHER *EVP_cast5_ecb(void);
 %name(cast5_cbc) extern EVP_CIPHER *EVP_cast5_cbc(void);
 %name(cast5_cfb) extern EVP_CIPHER *EVP_cast5_cfb(void);
