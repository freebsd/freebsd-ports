--- init_tls_context.c.orig	2015-05-07 23:53:06 UTC
+++ init_tls_context.c
@@ -1,6 +1,7 @@
 #include "tinytls.h"
 #include "open.h"
 #include <unistd.h>
+#include <string.h>
 
 void init_tls_context_norandom(struct ssl_context* sc, const char* servername) {
   memset(sc,0,sizeof *sc);
