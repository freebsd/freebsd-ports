--- lib/krb5/krb5_locl.h.orig	2019-06-07 06:21:39 UTC
+++ lib/krb5/krb5_locl.h
@@ -143,7 +143,7 @@ struct _krb5_krb_auth_data;
 #include <krb5.h>
 #include <krb5_err.h>
 #include <asn1_err.h>
-#ifdef PKINIT
+#if defined(PKINIT) || defined(KX509)
 #include <hx509.h>
 #endif
 
@@ -271,7 +271,7 @@ typedef struct krb5_context_data {
 #define KRB5_CTX_F_RD_REQ_IGNORE		16
 #define KRB5_CTX_F_FCACHE_STRICT_CHECKING	32
     struct send_to_kdc *send_to_kdc;
-#ifdef PKINIT
+#if defined(PKINIT) || defined(KX509)
     hx509_context hx509ctx;
 #endif
     unsigned int num_kdc_requests;
