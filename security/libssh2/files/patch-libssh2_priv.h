--- include/libssh2_priv.h.orig	2009-01-31 11:23:49.000000000 -0800
+++ include/libssh2_priv.h	2009-01-31 11:24:00.000000000 -0800
@@ -44,6 +44,8 @@
 
 #include <sys/socket.h>
 #include <openssl/evp.h>
+#include <openssl/md5.h>
+#include <openssl/sha.h>
 
 #define LIBSSH2_ALLOC(session, count)								session->alloc((count), &(session)->abstract)
 #define LIBSSH2_REALLOC(session, ptr, count)						session->realloc((ptr), (count), &(session)->abstract)
