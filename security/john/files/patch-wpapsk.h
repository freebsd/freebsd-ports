--- wpapsk.h.orig	2014-10-03 01:08:17 UTC
+++ wpapsk.h
@@ -13,6 +13,9 @@
 #include "arch.h"
 #include "common.h"
 #include "johnswap.h"
+#include "md5.h"
+#include "hmacmd5.h"
+#include "pbkdf2_hmac_sha1.h"
 #include "stdint.h"
 
 #include <assert.h>
@@ -200,7 +203,6 @@ static int valid(char *ciphertext, struct fmt_main *se
 #ifndef JOHN_OCL_WPAPSK
 static MAYBE_INLINE void prf_512(uint32_t * key, uint8_t * data, uint32_t * ret)
 {
-	HMAC_CTX ctx;
 	char *text = (char*)"Pairwise key expansion";
 	unsigned char buff[100];
 
@@ -208,10 +210,7 @@ static MAYBE_INLINE void prf_512(uint32_t * key, uint8
 	memcpy(buff + 23, data, 76);
 	buff[22] = 0;
 	buff[76 + 23] = 0;
-	HMAC_Init(&ctx, key, 32, EVP_sha1());
-	HMAC_Update(&ctx, buff, 100);
-	HMAC_Final(&ctx, (unsigned char *) ret, NULL);
-	HMAC_CTX_cleanup(&ctx);
+	hmac_sha1((unsigned char*)key, 32, buff, 100, (unsigned char*)ret, 20);
 }
 #endif
 
@@ -346,9 +345,12 @@ static void wpapsk_postprocess(int keys)
 #endif
 		for (i = 0; i < keys; i++) {
 			uint32_t prf[20/4];
+			HMACMD5Context ctx;
+
 			prf_512(outbuffer[i].v, data, prf);
-			HMAC(EVP_md5(), prf, 16, hccap.eapol, hccap.eapol_size,
-			    mic[i].keymic, NULL);
+			hmac_md5_init_K16((unsigned char*)prf, &ctx);
+			hmac_md5_update(hccap.eapol, hccap.eapol_size, &ctx);
+			hmac_md5_final(mic[i].keymic, &ctx);
 		}
 	} else {
 #ifdef _OPENMP
@@ -356,11 +358,10 @@ static void wpapsk_postprocess(int keys)
 #endif
 		for (i = 0; i < keys; i++) {
 			uint32_t prf[20/4];
-			unsigned char keymic[20];
+
 			prf_512(outbuffer[i].v, data, prf);
-			HMAC(EVP_sha1(), prf, 16, hccap.eapol,
-			    hccap.eapol_size, keymic, NULL);
-			memcpy(mic[i].keymic, keymic, 16);
+			hmac_sha1((unsigned char*)prf, 16, hccap.eapol,
+			          hccap.eapol_size, mic[i].keymic, 16);
 		}
 	}
 }
