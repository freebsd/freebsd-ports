--- unrar.h.orig	2014-05-16 13:40:40 UTC
+++ unrar.h
@@ -24,12 +24,12 @@
 #define UNRAR_H 1
 
 #include "arch.h"
-#include <openssl/evp.h>
 
 #include <sys/types.h>
 
 struct unpack_data_tag;
 
+#include "aes/aes.h"
 #include "unrarhlp.h"
 #include "unrarppm.h"
 #include "unrarvm.h"
@@ -198,7 +198,7 @@ typedef struct unpack_data_tag
 	rarvm_data_t rarvm_data;
 	unsigned int unp_crc;
 	unsigned int pack_size;
-	EVP_CIPHER_CTX *ctx;
+	AES_KEY *ctx;
 	unsigned char *key;
 	unsigned char *iv;
 } unpack_data_t;
