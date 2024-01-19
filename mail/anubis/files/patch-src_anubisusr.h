--- src/anubisusr.h.orig	2024-01-05 16:03:09 UTC
+++ src/anubisusr.h
@@ -25,10 +25,6 @@
 #include <gsasl.h>
 #include "getopt.h"
 
-#define obstack_chunk_alloc malloc
-#define obstack_chunk_free free
-#include <obstack.h>
-
 #if defined(USE_GNUTLS)
 # include <gnutls/gnutls.h>
 # define HAVE_TLS
