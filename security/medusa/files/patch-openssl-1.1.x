From 349ef7f0c24b627c6dbba8bcd5b47173806473a2 Mon Sep 17 00:00:00 2001
From: jmk-foofus <jmk@foofus.net>
Origin: https://github.com/jmk-foofus/medusa/commit/349ef7f0c24b627c6dbba8bcd5b47173806473a2
Date: Tue, 1 Nov 2016 16:26:12 -0500
Subject: [PATCH] Update to support newer versions of OpenSSL.

---
 config.h.in             |  6 ++++++
 configure               | 13 ++++++++++---
 configure.ac            |  2 +-
 src/medusa-net.c        |  9 +++++----
 src/medusa-thread-ssl.c | 10 +++++++---
 src/medusa.h            |  4 ++++
 src/modsrc/vnc.c        | 12 +++++++++---
 7 files changed, 42 insertions(+), 14 deletions(-)

--- config.h.in
+++ config.h.in
@@ -82,6 +82,12 @@
 /* Define to 1 if you have the <memory.h> header file. */
 #undef HAVE_MEMORY_H
 
+/* Define to 1 if you have the <openssl/crypto.h> header file. */
+#undef HAVE_OPENSSL_CRYPTO_H
+
+/* Define to 1 if you have the <openssl/ssl.h> header file. */
+#undef HAVE_OPENSSL_SSL_H
+
 /* Define to 1 if you have the <stdint.h> header file. */
 #undef HAVE_STDINT_H
 
--- src/medusa-net.c
+++ src/medusa-net.c
@@ -327,7 +327,9 @@ RSA *sslTempRSACallback(SSL * ssl __attr
   RSA *rsa = NULL;
 
   if (rsa == NULL)
-    rsa = RSA_generate_key(512, RSA_F4, NULL, NULL);
+    /* https://openssl.org/docs/manmaster/crypto/RSA_generate_key.html */
+    RSA_generate_key_ex(rsa, 512, (BIGNUM*) RSA_F4, NULL);
+
   return rsa;
 }
 
@@ -347,12 +349,12 @@ int medusaConnectSSLInternal(sConnectPar
      the server demands. The module can override this by setting nSSLVersion. */
 
   /* Debian's OpenSSL has SSLv2 support disabled. */
-#ifndef OPENSSL_NO_SSL2
+#if !defined(OPENSSL_NO_SSL2) && (OPENSSL_VERSION_NUMBER < 0x10100005L)
   if (pParams->nSSLVersion == 2)
     sslContext = SSL_CTX_new(SSLv2_client_method());
   else
 #endif
-#ifndef OPENSSL_NO_SSL3
+#if !defined(OPENSSL_NO_SSL3) && (OPENSSL_VERSION_NUMBER < 0x10100005L)
   if (pParams->nSSLVersion == 3)
     sslContext = SSL_CTX_new(SSLv3_client_method());
   else
@@ -378,7 +380,6 @@ int medusaConnectSSLInternal(sConnectPar
 
   // we set the default verifiers and dont care for the results
   SSL_CTX_set_default_verify_paths(sslContext);
-  SSL_CTX_set_tmp_rsa_callback(sslContext, sslTempRSACallback);
   SSL_CTX_set_verify(sslContext, SSL_VERIFY_NONE, NULL);
 
   if ((hSocket < 0) && ((hSocket = medusaConnect(pParams)) < 0))
--- src/medusa-thread-ssl.c
+++ src/medusa-thread-ssl.c
@@ -13,7 +13,11 @@
 
 #include "medusa.h"
 
-#ifdef HAVE_LIBSSL
+/* In OpenSSL <= 1.0.2, an application had to set locking callbacks to use
+   OpenSSL in a multi-threaded environment. OpenSSL 1.1.0 now finds pthreads
+   or Windows threads, so nothing special is necessary.
+*/
+#if defined(HAVE_LIBSSL) && (OPENSSL_VERSION_NUMBER < 0x10100005L) 
 static pthread_mutex_t *lockarray;
 
 #include <openssl/crypto.h>
@@ -79,7 +83,7 @@ void init_locks_gnutls(void)
 
 void init_crypto_locks(void)
 {
-#ifdef HAVE_LIBSSL
+#if defined(HAVE_LIBSSL) && (OPENSSL_VERSION_NUMBER < 0x10100005L) 
   init_locks_openssl();
 #endif
 
@@ -90,7 +94,7 @@ void init_crypto_locks(void)
 
 void kill_crypto_locks(void)
 {
-#ifdef HAVE_LIBSSL
+#if defined(HAVE_LIBSSL) && (OPENSSL_VERSION_NUMBER < 0x10100005L) 
   kill_locks_openssl();
 #endif
 }
--- src/medusa.h
+++ src/medusa.h
@@ -44,6 +44,10 @@
   #include <config.h>
 #endif
 
+#ifdef HAVE_LIBSSL
+  #include <openssl/crypto.h>
+#endif
+
 #define PROGRAM   "Medusa"
 #ifndef VERSION
   #define VERSION   "1.0"
--- src/modsrc/vnc.c
+++ src/modsrc/vnc.c
@@ -811,7 +811,10 @@ int sendAuthMSLogin(int hSocket, _VNC_DA
 
   /* create and populate DH structure */ 
   dh_struct = DH_new();
- 
+
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L 
+  DH_set0_pqg(dh_struct, (BIGNUM*) &p, (BIGNUM*) &client_priv, (BIGNUM*) &g);
+#else 
   dh_struct->g = BN_new();
   BN_set_word(dh_struct->g, g);
   
@@ -820,12 +823,11 @@ int sendAuthMSLogin(int hSocket, _VNC_DA
   
   dh_struct->priv_key = BN_new();
   BN_set_word(dh_struct->priv_key, client_priv);
+#endif
 
   if (DH_generate_key(dh_struct) == 0)
     writeError(ERR_ERROR, "[%s] Failed to generate key", MODULE_NAME);
   
-  writeError(ERR_DEBUG_MODULE, "[%s] Client DH private key: %s public key: %s", MODULE_NAME, BN_bn2hex(dh_struct->priv_key), BN_bn2hex(dh_struct->pub_key));
-  
   DH_check(dh_struct, &dh_error);
   if (dh_error & DH_CHECK_P_NOT_SAFE_PRIME)
     writeError(ERR_DEBUG_MODULE, "[%s] Failed to create DH structure: DH_CHECK_P_NOT_SAFE_PRIME", MODULE_NAME);
@@ -835,7 +837,11 @@ int sendAuthMSLogin(int hSocket, _VNC_DA
     writeError(ERR_DEBUG_MODULE, "[%s] Failed to create DH structure: DH_UNABLE_TO_CHECK_GENERATOR", MODULE_NAME);
 
   /* convert client public key into proper format for sending */
+#if OPENSSL_VERSION_NUMBER >= 0x10100005L 
+  DH_set0_key(dh_struct, (BIGNUM*) &client_pub, (BIGNUM*) &client_priv);
+#else
   int64ToBytes(BN_get_word(dh_struct->pub_key), client_pub);
+#endif
 
   /* generate shared secret using private DH key and server's public key */
   server_pub = BN_new();
