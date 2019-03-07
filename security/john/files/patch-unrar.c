--- unrar.c.orig	2014-09-19 16:40:51 UTC
+++ unrar.c
@@ -31,7 +31,6 @@
 #include <errno.h>
 #include <stdlib.h>
 #include <string.h>
-#include <openssl/evp.h>
 
 #include "unrar.h"
 #include "unrarppm.h"
@@ -136,13 +135,7 @@ int rar_unp_read_buf(const unsigned char **fd, unpack_
 	}
 
 	if (read_size) {
-		int outlen;
-
-		EVP_DecryptUpdate(unpack_data->ctx, unpack_data->in_buf + data_size, &outlen, *fd, read_size);
-		if (outlen > read_size - 16) {
-			EVP_DecryptFinal_ex(unpack_data->ctx, unpack_data->in_buf + data_size + outlen, &outlen);
-		} else
-			read_size = outlen;
+		AES_cbc_encrypt(*fd, unpack_data->in_buf + data_size, read_size, unpack_data->ctx, unpack_data->iv, AES_DECRYPT);
 		*fd += read_size;
 		unpack_data->read_top += read_size;
 		unpack_data->pack_size -= read_size;
