--- pcode.c.orig	Sun Mar  7 17:37:56 2004
+++ pcode.c	Sun Feb 22 06:14:06 2004
@@ -21,10 +21,14 @@
 /* Password encryption/decryption data structures and routines */
 
 #include <sys/param.h>
+#if defined(USE_OPENSSL)
+#include <openssl/des.h>
+#else /* ! OpenSSL */
 #if (defined(BSD) && BSD >= 199306)
  #include <unistd.h>
  #include <stdlib.h>
 #endif
+#endif /* OpenSSL */
 
 static unsigned char pkey[8] = {0x87,0xB6,0xAC,0xAF,0xC6,0xC8,0x94,0x8C},
 					 ukey[64], upwd[64];
@@ -68,15 +72,27 @@
 void pencode(unsigned char *ep, unsigned char *pp)
 {
 	int i;
+#if defined(USE_OPENSSL)
+	DES_key_schedule key;
+#else
 #if !(defined(BSD) && BSD >= 199306)
  	void setkey(), encrypt();
 #endif
+#endif
 
 	cupack(ukey, pkey);				/* unpack the key */
+#if defined(USE_OPENSSL)
+	DES_set_key((DES_cblock *)ukey, &key);
+#else
 	setkey(ukey);					/* insert it in crypt's machine */
+#endif
 	for (i=0; i<8; i++) {			/* do all 64 bytes */
 		cupack(upwd, pp);			/* unpack the plain-text password */
+#if defined(USE_OPENSSL)
+		DES_ecb_encrypt((const_DES_cblock *)upwd, (DES_cblock *)upwd, &key, 1);
+#else
 		encrypt(upwd, 0);			/* encrypt it in place */
+#endif
 		cpack(ep, upwd);			/* copy it out into the result */
 		ep += 8; pp += 8;			/* get next 8 bytes */
 	}
@@ -86,15 +102,27 @@
 void pdecode(unsigned char *pp, unsigned char *ep)
 {
 	int i;
+#if defined(USE_OPENSSL)
+	DES_key_schedule key;
+#else
 #if !(defined(BSD) && BSD >= 199306)
 	void setkey(), encrypt();
 #endif
+#endif
 
 	cupack(ukey, pkey);				/* unpack the key */
+#if defined(USE_OPENSSL)
+	DES_set_key((DES_cblock *)ukey, &key);
+#else
 	setkey(ukey);					/* insert it in crypt's machine */
+#endif
 	for (i=0; i<8; i++) {			/* do all 64 bytes */
 		cupack(upwd, ep);			/* unpack the encrypted password */
+#if defined(USE_OPENSSL)
+		DES_ecb_encrypt((const_DES_cblock *)upwd, (DES_cblock *)upwd, &key, 0);
+#else
 		encrypt(upwd, 1);			/* decrypt it in place */
+#endif
 		cpack(pp, upwd);			/* copy it out into the result */
 		ep += 8; pp += 8;			/* get next 8 bytes */
 	}
