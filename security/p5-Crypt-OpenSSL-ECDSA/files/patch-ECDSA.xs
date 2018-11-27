--- ECDSA.xs.orig	2015-01-02 01:24:13 UTC
+++ ECDSA.xs
@@ -7,9 +7,34 @@
 
 #include <openssl/ecdsa.h>
 #include <openssl/err.h>
+#include <openssl/bn.h>
 
 #include "const-c.inc"
 
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#include <openssl/ec.h>
+#else
+static void ECDSA_SIG_get0(const ECDSA_SIG *sig, const BIGNUM **pr,
+    const BIGNUM **ps) {
+    if (pr != NULL)
+        *pr = sig->r;
+    if (ps != NULL)
+        *ps = sig->s;
+}
+
+static int ECDSA_SIG_set0(ECDSA_SIG *sig, BIGNUM *r, BIGNUM *s)
+{
+    if (r == NULL || s == NULL)
+        return 0;
+    BN_clear_free(sig->r);
+    BN_clear_free(sig->s);
+    sig->r = r;
+    sig->s = s;
+    return 1;
+}
+#endif
+
 MODULE = Crypt::OpenSSL::ECDSA		PACKAGE = Crypt::OpenSSL::ECDSA
 
 PROTOTYPES: ENABLE
@@ -17,7 +42,9 @@ INCLUDE: const-xs.inc
 
 BOOT:
     ERR_load_crypto_strings();
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && OPENSSL_VERSION_NUMBER < 0x10100000L
     ERR_load_ECDSA_strings();
+#endif
 
 #ECDSA_SIG *
 #ECDSA_SIG_new()
@@ -61,10 +88,16 @@ ECDSA_do_verify(const unsigned char *dgst, const ECDSA
 	OUTPUT:
 		RETVAL
 
-# These ECDSA_METHOD functions only became available in 1.0.2
+# These ECDSA_METHOD functions only became available in 1.0.2,
+# but some of them removed again in 1.1.0.
 
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L
 
+int	  
+ECDSA_size(const EC_KEY *eckey)
+
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+
 const ECDSA_METHOD *
 ECDSA_OpenSSL()
 
@@ -77,9 +110,6 @@ ECDSA_get_default_method()
 int 	  
 ECDSA_set_method(EC_KEY *eckey, const ECDSA_METHOD *meth)
 
-int	  
-ECDSA_size(const EC_KEY *eckey)
-
 ECDSA_METHOD *
 ECDSA_METHOD_new(ECDSA_METHOD *ecdsa_method=0)
 
@@ -95,8 +125,8 @@ ECDSA_METHOD_set_name(ECDSA_METHOD *ecdsa_method, char
 void 
 ERR_load_ECDSA_strings()
 
-
 #endif
+#endif
 
 
 
@@ -135,11 +165,13 @@ SV *
 get_r(ecdsa_sig)
         ECDSA_SIG *ecdsa_sig
     PREINIT:
+        const BIGNUM *r;
         unsigned char *to;
         STRLEN len;
     CODE:
         to = malloc(sizeof(char) * 128);
-        len = BN_bn2bin(ecdsa_sig->r, to);
+        ECDSA_SIG_get0(ecdsa_sig, &r, NULL);
+        len = BN_bn2bin(r, to);
         RETVAL = newSVpvn((const char*)to, len);
         free(to);
     OUTPUT:
@@ -149,11 +181,13 @@ SV *
 get_s(ecdsa_sig)
         ECDSA_SIG *ecdsa_sig
     PREINIT:
+        const BIGNUM *s;
         unsigned char *to;
         STRLEN len;
     CODE:
         to = malloc(sizeof(char) * 128);
-        len = BN_bn2bin(ecdsa_sig->s, to);
+        ECDSA_SIG_get0(ecdsa_sig, NULL, &s);
+        len = BN_bn2bin(s, to);
         RETVAL = newSVpvn((const char*)to, len);
         free(to);
     OUTPUT:
@@ -164,26 +198,36 @@ set_r(ecdsa_sig, r_SV)
         ECDSA_SIG *ecdsa_sig
         SV * r_SV
     PREINIT:
-	char *s;
+	    char *string;
         STRLEN len;
+        BIGNUM *r;
+        BIGNUM *s;
     CODE:
-        s = SvPV(r_SV, len);
-        if (ecdsa_sig->r)
-            BN_free(ecdsa_sig->r);
-        ecdsa_sig->r = BN_bin2bn((const unsigned char *)s, len, NULL);
+        string = SvPV(r_SV, len);
+        r = BN_bin2bn((const unsigned char *)string, len, NULL);
+        ECDSA_SIG_get0(ecdsa_sig, NULL, (const BIGNUM**)&s);
+        s = BN_dup(s);
+        if (NULL == s)
+            croak("Could not duplicate unchanged ECDSA paramater");
+        ECDSA_SIG_set0(ecdsa_sig, r, s);
 
 void
 set_s(ecdsa_sig, s_SV)
         ECDSA_SIG *ecdsa_sig
         SV * s_SV
     PREINIT:
-	char *s;
+	    char *string;
         STRLEN len;
+        BIGNUM *r;
+        BIGNUM *s;
     CODE:
-        s = SvPV(s_SV, len);
-        if (ecdsa_sig->s)
-            BN_free(ecdsa_sig->s);
-        ecdsa_sig->s = BN_bin2bn((const unsigned char *)s, len, NULL);
+        string = SvPV(s_SV, len);
+        s = BN_bin2bn((const unsigned char *)string, len, NULL);
+        ECDSA_SIG_get0(ecdsa_sig, (const BIGNUM**)&r, NULL);
+        r = BN_dup(r);
+        if (NULL == r)
+            croak("Could not duplicate unchanged ECDSA paramater");
+        ECDSA_SIG_set0(ecdsa_sig, r, s);
 
 
 
