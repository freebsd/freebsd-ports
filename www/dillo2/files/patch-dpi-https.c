--- dpi/https.c.orig	Sun Oct  3 17:16:15 2004
+++ dpi/https.c	Sun Oct  3 17:17:47 2004
@@ -53,7 +53,6 @@
 #include <glib.h>
 #include "dpiutil.h"
 
-#undef ENABLE_SSL
 #ifdef ENABLE_SSL
 
 #include <openssl/ssl.h>
@@ -605,13 +616,8 @@ static void no_ssl_support(void)
       "<b>}</b>\n\n"
       "  <b>*** Dillo's prototype plugin for https support"
       " is disabled now ***</b>\n\n"
-      "  If you want to test this <b>alpha</b> support code, just remove\n"
-      "  line 56 from https.c, recompile and reinstall.\n\n"
-      "  (beware that this https support is very limited now)\n\n"
-      "  To use https and SSL, you must have \n"
-      "  the OpenSSL development libraries installed.  Check your\n"
-      "  O/S distribution provider, or check out\n"
-      "  <a href=\"http://www.openssl.org\">www.openssl.org</a>\n\n"
+      "  If you want to test this <b>alpha</b> support code, define\n"
+      "  WITH_DILLO_SSL in your make environment and rebuild the port.\n\n"
       "  --\n"
       "</pre></body></html>\n",
       http_query
