Source: https://github.com/processone/fast_tls/commit/a2b2154d11280becbf3077e62f7b5621d52b54fd

--- deps/fast_tls/c_src/fast_tls.c.orig	2017-12-14 19:39:12 UTC
+++ deps/fast_tls/c_src/fast_tls.c
@@ -57,7 +57,7 @@ typedef unsigned __int32 uint32_t;
 #define SSL_OP_NO_TICKET 0
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined LIBRESSL_VERSION_NUMBER
 #define DH_set0_pqg(dh, dh_p, param, dh_g) (dh)->p = dh_p; (dh)->g = dh_g
 #define our_alloc enif_alloc
 #define our_realloc enif_realloc
@@ -347,7 +347,7 @@ static void unload(ErlNifEnv *env, void 
 
     for (i = 0; i < CRYPTO_num_locks(); i++)
         enif_mutex_destroy(mtx_buf[i]);
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined LIBRESSL_VERSION_NUMBER
     OPENSSL_cleanup();
 #endif
 }
