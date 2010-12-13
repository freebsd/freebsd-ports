diff --git modules/dbparser/patternize.c.orig modules/dbparser/patternize.c
index 1a433c2..b22a9c7 100644
--- modules/dbparser/patternize.c.orig
+++ modules/dbparser/patternize.c
@@ -27,7 +27,6 @@
 
 #include <stdlib.h>
 #include <string.h>
-#include <openssl/rand.h>
 
 /*
  * NOTE: most of the algorithms come from SLCT and LogHound, written by Risto Vaarandi
@@ -45,6 +44,10 @@
 static LogTagId cluster_tag_id;
 
 
+#if ENABLE_SSL_MODULE
+
+#include <openssl/rand.h>
+
 static void
 uuid_gen_random(gchar *buf, gsize buflen)
 {
@@ -77,6 +80,19 @@ uuid_gen_random(gchar *buf, gsize buflen)
 
 }
 
+#else
+
+#warning "openssl seems to be missing on your system, UUID generation will be disabled in pdbtool patternize"
+
+static void
+uuid_gen_random(gchar *buf, gsize buflen)
+{
+  static int counter = 1;
+
+  g_snprintf(buf, buflen, "unable-to-generate-uuid-without-random-source-%d", counter++);
+}
+#endif
+
 #if 0
 static void _ptz_debug_print_word(gpointer key, gpointer value, gpointer dummy)
 {
