--- s_cb.c.orig	Wed Oct 15 22:29:17 2003
+++ s_cb.c	Wed Oct 15 22:29:31 2003
@@ -63,9 +63,9 @@
 #include "apps.h"
 #undef NON_MAIN
 #undef USE_SOCKETS
-#include OPENSSL"err.h"
-#include OPENSSL"x509.h"
-#include OPENSSL"ssl.h"
+#include "%%OPENSSL%%/err.h"
+#include "%%OPENSSL%%/x509.h"
+#include "%%OPENSSL%%/ssl.h"
 #include "s_apps.h"
 
 int verify_depth=0;
