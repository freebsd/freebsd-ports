--- src/ssl.c.orig	2008-11-22 17:49:07.000000000 +0100
+++ src/ssl.c	2008-11-22 17:50:17.000000000 +0100
@@ -16,11 +16,13 @@
 #endif		/* HAVE_ERR_H */
 
 #ifdef		HANDLE_SSL
+# define	MD5_CTX		OpenSSL_MD5_CTX
 #include	<openssl/rand.h>
 #include	<openssl/err.h>
 #include	<openssl/conf.h>
 #include	<openssl/ssl.h>
 #include	<openssl/tls1.h>
+# undef		MD5_CTX
 #endif		/* HANDLE_SSL */
 
 #include	"htconfig.h"
--- src/ssl.h.orig	2008-11-22 17:49:11.000000000 +0100
+++ src/ssl.h	2008-11-22 17:50:17.000000000 +0100
@@ -11,8 +11,10 @@
 #  define	OPENSSL_NO_MD5
 #  define	HEADER_MD5_H	/* trick older openssl */
 # endif		/* Not USE_OPENSSL_MD5 */
+# define	MD5_CTX		OpenSSL_MD5_CTX
 # include	<openssl/ssl.h>
 # include	<openssl/tls1.h>
+# undef		MD5_CTX
 # ifdef		TLSEXT_NAMETYPE_host_name
 #  ifndef	OPENSSL_NO_TLSEXT
 #   define	HANDLE_SSL_TLSEXT
