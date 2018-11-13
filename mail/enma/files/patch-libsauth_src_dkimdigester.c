--- ./libsauth/src/dkimdigester.c.org	2011-10-16 17:08:36.000000000 +0900
+++ ./libsauth/src/dkimdigester.c	2018-11-11 18:20:49.869300000 +0900
@@ -32,12 +32,17 @@
 #include "dkimpolicybase.h"
 #include "dkimdigester.h"
 
+#if (OPENSSL_VERSION_NUMBER < 0x10100000L)
+#define EVP_MD_CTX_new EVP_MD_CTX_create
+#define EVP_MD_CTX_free EVP_MD_CTX_destroy
+#endif
+
 struct DkimDigester {
     const DkimPolicyBase *policy;
     const EVP_MD *digest_alg;
     int pubkey_alg;
-    EVP_MD_CTX header_digest;
-    EVP_MD_CTX body_digest;
+    EVP_MD_CTX *header_digest;
+    EVP_MD_CTX *body_digest;
     DkimCanonicalizer *canon;
     /// body length limit. sig-l-tag itself. -1 for unlimited.
     long long body_length_limit;
@@ -210,13 +215,23 @@
     if (NULL == self->canon) {
         goto cleanup;
     }   // end if
-    if (0 == EVP_DigestInit(&(self->header_digest), self->digest_alg)) {
+    if (NULL == (self->header_digest = EVP_MD_CTX_new())) {
+        DkimLogNoResource(self->policy);
+        DkimDigester_free(self);
+        return DSTAT_SYSERR_NORESOURCE;
+    }   // end if
+    if (0 == EVP_DigestInit(self->header_digest, self->digest_alg)) {
         DkimLogSysError(policy, "Digest Initialization (of header) failed");
         DkimDigester_logOpenSSLErrors(self);
         SETDEREF(dstat, DSTAT_SYSERR_NORESOURCE);
         goto cleanup;
     }   // end if
-    if (0 == EVP_DigestInit(&(self->body_digest), self->digest_alg)) {
+    if (NULL == (self->body_digest = EVP_MD_CTX_new())) {
+        DkimLogNoResource(self->policy);
+        DkimDigester_free(self);
+        return DSTAT_SYSERR_NORESOURCE;
+    }   // end if
+    if (0 == EVP_DigestInit(self->body_digest, self->digest_alg)) {
         DkimLogSysError(policy, "Digest Initialization (of body) failed");
         DkimDigester_logOpenSSLErrors(self);
         SETDEREF(dstat, DSTAT_SYSERR_NORESOURCE);
@@ -246,9 +261,14 @@
     if (NULL != self->canon) {
         DkimCanonicalizer_free(self->canon);
     }   // end if
-    (void) EVP_MD_CTX_cleanup(&(self->header_digest));
-    (void) EVP_MD_CTX_cleanup(&(self->body_digest));
 
+    if (NULL != self->header_digest) {
+        EVP_MD_CTX_free(self->header_digest);
+    }
+    if (NULL != self->body_digest) {
+        EVP_MD_CTX_free(self->body_digest);
+    }
+
     // No need to clean up "self->digest_alg"
 
     free(self);
@@ -289,7 +309,7 @@
     }   // end if
 
     if (0 < srclen) {
-        if (0 == EVP_DigestUpdate(&self->body_digest, buf, srclen)) {
+        if (0 == EVP_DigestUpdate(self->body_digest, buf, srclen)) {
             DkimLogSysError(self->policy, "Digest update (of body) failed");
             DkimDigester_logOpenSSLErrors(self);
             return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
@@ -360,7 +380,7 @@
     // discard errors occurred in functions for debugging
     (void) DkimDigester_dumpCanonicalizedHeader(self, canonbuf, canonsize);
 
-    if (0 == EVP_DigestUpdate(&self->header_digest, canonbuf, canonsize)) {
+    if (0 == EVP_DigestUpdate(self->header_digest, canonbuf, canonsize)) {
         DkimLogSysError(self->policy, "Digest update (of header) failed");
         DkimDigester_logOpenSSLErrors(self);
         return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
@@ -487,7 +507,7 @@
     (void) DkimDigester_dumpCanonicalizedHeader(self, canonbuf, canonsize);
 
     // update digest
-    if (0 == EVP_DigestUpdate(&self->header_digest, canonbuf, canonsize)) {
+    if (0 == EVP_DigestUpdate(self->header_digest, canonbuf, canonsize)) {
         DkimLogSysError(self->policy, "Digest update (of signature header) failed");
         DkimDigester_logOpenSSLErrors(self);
         return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
@@ -524,9 +544,9 @@
 
     // check if the type of the public key is suitable for the algorithm
     // specified by sig-a-tag of the DKIM-Signature header.
-    if (publickey->type != self->pubkey_alg) {
+    if (EVP_PKEY_base_id(publickey) != self->pubkey_alg) {
         DkimLogPermFail(self->policy, "Public key algorithm mismatch: signature=0x%x, pubkey=0x%x",
-                        publickey->type, self->pubkey_alg);
+                        EVP_PKEY_base_id(publickey), self->pubkey_alg);
         return DSTAT_PERMFAIL_PUBLICKEY_TYPE_MISMATCH;
     }   // end if
 
@@ -541,7 +561,7 @@
     if (DSTAT_OK != ret) {
         return ret;
     }   // end if
-    if (0 == EVP_DigestFinal(&self->body_digest, md, &mdlen)) {
+    if (0 == EVP_DigestFinal(self->body_digest, md, &mdlen)) {
         DkimLogSysError(self->policy, "Digest finish (of body) failed");
         DkimDigester_logOpenSSLErrors(self);
         return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
@@ -573,7 +593,7 @@
     const XBuffer *headerhash = DkimSignature_getSignatureValue(signature);
     signbuf = (const unsigned char *) XBuffer_getBytes(headerhash);
     signlen = XBuffer_getSize(headerhash);
-    int vret = EVP_VerifyFinal(&self->header_digest, signbuf, signlen, publickey);
+    int vret = EVP_VerifyFinal(self->header_digest, signbuf, signlen, publickey);
     // EVP_VerifyFinal() returns 1 for a correct signature, 0 for failure and -1 if some other error occurred.
     switch (vret) {
     case 1:    // the signature is correct
@@ -614,10 +634,10 @@
     assert(NULL != privatekey);
 
     // XXX signature と self の署名/ダイジェストアルゴリズムが一致しているか確認した方がいい
-    if (privatekey->type != self->pubkey_alg) {
+    if (EVP_PKEY_base_id(privatekey) != self->pubkey_alg) {
         DkimLogPermFail(self->policy,
                         "Public key algorithm mismatch: signature=0x%x, privatekey=0x%x",
-                        privatekey->type, self->pubkey_alg);
+                        EVP_PKEY_base_id(privatekey), self->pubkey_alg);
         return DSTAT_PERMFAIL_PUBLICKEY_TYPE_MISMATCH;
     }   // end if
 
@@ -636,7 +656,7 @@
     unsigned char bodyhashbuf[EVP_MD_size(self->digest_alg)];   // EVP_MAX_MD_SIZE instead of EVP_MD_size() is safer(?)
     unsigned int bodyhashlen;
     bodyhashlen = EVP_MD_size(self->digest_alg);
-    if (0 == EVP_DigestFinal(&self->body_digest, bodyhashbuf, &bodyhashlen)) {
+    if (0 == EVP_DigestFinal(self->body_digest, bodyhashbuf, &bodyhashlen)) {
         DkimLogSysError(self->policy, "DigestFinal (of body) failed");
         DkimDigester_logOpenSSLErrors(self);
         return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
@@ -676,7 +696,7 @@
 
     unsigned char signbuf[EVP_PKEY_size(privatekey)];
     unsigned int signlen;
-    if (0 == EVP_SignFinal(&self->header_digest, signbuf, &signlen, privatekey)) {
+    if (0 == EVP_SignFinal(self->header_digest, signbuf, &signlen, privatekey)) {
         DkimLogSysError(self->policy, "SignFinal (of body) failed");
         DkimDigester_logOpenSSLErrors(self);
         return DSTAT_SYSERR_DIGEST_UPDATE_FAILURE;
