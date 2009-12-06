--- libiapp/iapp_ssl.h  (revision 12992)
+++ libiapp/iapp_ssl.h  (working copy)
@@ -3,6 +3,9 @@
 
 #include "../include/config.h"
 
+/* Don't include these if we are -not- building with SSL support */
+
+#if USE_SSL
 #if HAVE_OPENSSL_SSL_H
 #include <openssl/ssl.h>
 #endif
@@ -12,5 +15,6 @@
 #if HAVE_OPENSSL_ENGINE_H
 #include <openssl/engine.h>
 #endif
+#endif /* USE_SSL */
 
 #endif
