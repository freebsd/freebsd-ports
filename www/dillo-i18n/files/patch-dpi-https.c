--- dpi/https.c.orig	Sat Mar 25 16:49:59 2006
+++ dpi/https.c	Sat Mar 25 16:55:35 2006
@@ -655,13 +655,8 @@
       "<b>}</b>\n\n"
       "  <b>*** Dillo's prototype plugin for https support"
       " is disabled now ***</b>\n\n"
-      "  If you want to test this <b>alpha</b> support code, just remove\n"
-      "  line 65 from https.c, recompile and reinstall.\n\n"
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
