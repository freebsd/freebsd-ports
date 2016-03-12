--- src/mod/event_handlers/mod_rayo/xmpp_streams.c.orig	2016-01-12 16:32:36 UTC
+++ src/mod/event_handlers/mod_rayo/xmpp_streams.c
@@ -29,6 +29,8 @@
 #include <switch.h>
 #include <iksemel.h>
 
+int iks_proceed_tls (iksparser *prs, const char *cert_file, const char *key_file);
+
 #include <openssl/ssl.h>
 
 #include "xmpp_streams.h"
