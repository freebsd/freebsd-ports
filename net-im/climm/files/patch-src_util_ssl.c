--- src/util_ssl.c.orig	Thu Dec 16 22:36:52 2004
+++ src/util_ssl.c	Thu Dec 16 22:37:28 2004
@@ -210,6 +210,7 @@
 
 #else /* ENABLE_GNUTLS */
 
+    DH *dh;
     SSL_library_init();
     gSSL_CTX = SSL_CTX_new (TLSv1_method ());
 #if OPENSSL_VERSION_NUMBER >= 0x00905000L
@@ -221,7 +222,7 @@
     if (prG->verbose & DEB_SSL)
         SSL_CTX_set_info_callback (gSSL_CTX, (void (*)())openssl_info_callback);
 
-    DH *dh = get_dh512 ();
+    dh = get_dh512 ();
     if (!dh)
         return -1;
     SSL_CTX_set_tmp_dh (gSSL_CTX, dh);
