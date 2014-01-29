--- ./htmldoc/http-private.h.orig	2011-12-30 08:41:10.000000000 +0100
+++ ./htmldoc/http-private.h	2014-01-28 04:47:41.000000000 +0100
@@ -83,12 +83,12 @@
 #  endif /* __sgi || (__APPLE__ && !_SOCKLEN_T) */
 
 #  include "http.h"
-#  include "md5-private.h"
 
 #  if defined HAVE_LIBSSL
 #    include <openssl/err.h>
 #    include <openssl/rand.h>
 #    include <openssl/ssl.h>
+#    include <openssl/md5.h>
 #  elif defined HAVE_GNUTLS
 #    include <gnutls/gnutls.h>
 #    include <gnutls/x509.h>
@@ -276,7 +276,7 @@
   char			buffer[HTTP_MAX_BUFFER];
 					/* Buffer for incoming data */
   int			auth_type;	/* Authentication in use */
-  _cups_md5_state_t	md5_state;	/* MD5 state */
+  MD5_CTX		md5_state;	/* MD5 state */
   char			nonce[HTTP_MAX_VALUE];
 					/* Nonce value */
   int			nonce_count;	/* Nonce count */
