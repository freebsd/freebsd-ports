--- ./src/libgcrypt.c.orig	2012-02-07 19:05:00.000000000 +0100
+++ ./src/libgcrypt.c	2012-02-07 19:05:11.000000000 +0100
@@ -581,7 +581,7 @@
                           const char *privatekey,
                           const char *passphrase)
 {
-    return _libssh_error(session, LIBSSH2_ERROR_FILE,
+    return _libssh2_error(session, LIBSSH2_ERROR_FILE,
                          "Unable to extract public key from private key file: "
                          "Method unimplemented in libgcrypt backend");
 }
