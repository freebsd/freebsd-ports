===================================================================
RCS file: /cvsroot/meanwhile/meanwhile/src/cipher.h,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- src/cipher.h	2004/06/01 23:24:53	1.1
+++ src/cipher.h	2004/06/28 18:20:29	1.2
@@ -26,31 +26,31 @@
 
 /** Expand a variable-length key into a 128-byte key (represented as an
     an array of 64 ints) */
-void mwKeyExpand(int *ekey, const char *key, unsigned int keylen);
+void mwKeyExpand(int *ekey, const char *key, gsize keylen);
 
 
 /** Encrypt data using an already-expanded key */
 void mwEncryptExpanded(const int *ekey, char *iv,
-		       const char *in, unsigned int i_len,
-		       char **out, unsigned int *o_len);
+		       const char *in, gsize i_len,
+		       char **out, gsize *o_len);
 
 
 /** Encrypt data using an expanded form of the given key */
-void mwEncrypt(const char *key, unsigned int keylen, char *iv,
-	       const char *in, unsigned int i_len,
-	       char **out, unsigned int *o_len);
+void mwEncrypt(const char *key, gsize keylen, char *iv,
+	       const char *in, gsize i_len,
+	       char **out, gsize *o_len);
 
 
 /** Decrypt data using an already expanded key */
 void mwDecryptExpanded(const int *ekey, char *iv,
-		       const char *in, unsigned int i_len,
-		       char **out, unsigned int *o_len);
+		       const char *in, gsize i_len,
+		       char **out, gsize *o_len);
 
 
 /** Decrypt data using an expanded form of the given key */
-void mwDecrypt(const char *key, unsigned int keylen, char *iv,
-	       const char *in, unsigned int i_len,
-	       char **out, unsigned int *o_len);
+void mwDecrypt(const char *key, gsize keylen, char *iv,
+	       const char *in, gsize i_len,
+	       char **out, gsize *o_len);
 
 
 #endif
