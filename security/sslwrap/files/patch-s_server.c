--- s_server.c.orig	Sat Nov 11 14:11:18 2000
+++ s_server.c	Wed Oct 15 22:31:56 2003
@@ -121,14 +121,14 @@
 #ifdef WIN16
 #define APPS_WIN16
 #endif
-#include OPENSSL"lhash.h"
-#include OPENSSL"bn.h"
+#include "openssl//lhash.h"
+#include "openssl//bn.h"
 #define USE_SOCKETS
 #include "apps.h"
-#include OPENSSL"err.h"
-#include OPENSSL"pem.h"
-#include OPENSSL"x509.h"
-#include OPENSSL"ssl.h"
+#include "openssl//err.h"
+#include "openssl//pem.h"
+#include "openssl//x509.h"
+#include "openssl//ssl.h"
 #include "s_apps.h"
 
 #ifndef NOPROTO
@@ -468,7 +468,7 @@
 
 	if (bugs) SSL_CTX_set_options(ctx,SSL_OP_ALL);
 	if (hack) SSL_CTX_set_options(ctx,SSL_OP_NETSCAPE_DEMO_CIPHER_CHANGE_BUG);
-	if (hack) SSL_CTX_set_options(ctx,SSL_OP_NON_EXPORT_FIRST);
+	if (hack) SSL_CTX_set_options(ctx,SSL_OP_CIPHER_SERVER_PREFERENCE);
 
 	if (state) SSL_CTX_set_info_callback(ctx,apps_ssl_info_callback);
 
