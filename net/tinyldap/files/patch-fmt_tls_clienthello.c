--- fmt_tls_clienthello.c.orig	2015-05-07 23:53:05 UTC
+++ fmt_tls_clienthello.c
@@ -2,6 +2,7 @@
 #include "uint16.h"
 #include "uint32.h"
 #include <time.h>
+#include <string.h>
 
 size_t fmt_tls_clienthello(char* dest, struct ssl_context* sc) {
   size_t hnextlen=sc->servername?strlen(sc->servername)+9:0;
