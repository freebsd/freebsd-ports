===================================================================
RCS file: /cvsroot/meanwhile/meanwhile/src/cipher.c,v
retrieving revision 1.2
retrieving revision 1.3
diff -u -r1.2 -r1.3
--- src/cipher.c	2004/06/15 15:34:21	1.2
+++ src/cipher.c	2004/06/28 18:20:29	1.3
@@ -71,7 +71,7 @@
 /* This does not seem to produce the same results as normal RC2 key
    expansion would, but it works, so eh. It might be smart to farm
    this out to mozilla or openssl */
-void mwKeyExpand(int *ekey, const char *key, unsigned int keylen) {
+void mwKeyExpand(int *ekey, const char *key, gsize keylen) {
   char tmp[128];
   int i, j;
 
@@ -136,8 +136,8 @@
 
 
 void mwEncryptExpanded(const int *ekey, char *iv,
-		       const char *in, unsigned int i_len,
-		       char **out, unsigned int *o_len) {
+		       const char *in, gsize i_len,
+		       char **out, gsize *o_len) {
   int x, y;
   char *o;
   int o_l;
@@ -167,9 +167,9 @@
 }
 
 
-void mwEncrypt(const char *key, unsigned int keylen, char *iv,
-	       const char *in, unsigned int i_len,
-	       char **out, unsigned int *o_len) {
+void mwEncrypt(const char *key, gsize keylen, char *iv,
+	       const char *in, gsize i_len,
+	       char **out, gsize *o_len) {
 
   int ekey[64];
   mwKeyExpand(ekey, key, keylen);
@@ -220,8 +220,8 @@
 
 
 void mwDecryptExpanded(const int *ekey, char *iv,
-		       const char *in, unsigned int i_len,
-		       char **out, unsigned int *o_len) {
+		       const char *in, gsize i_len,
+		       char **out, gsize *o_len) {
   int x, y;
   char *o;
   int o_l;
@@ -256,9 +256,9 @@
 }
 
 
-void mwDecrypt(const char *key, unsigned int keylen, char *iv,
-	       const char *in, unsigned int i_len,
-	       char **out, unsigned int *o_len) {
+void mwDecrypt(const char *key, gsize keylen, char *iv,
+	       const char *in, gsize i_len,
+	       char **out, gsize *o_len) {
 
   int ekey[64];
   mwKeyExpand(ekey, key, keylen);
