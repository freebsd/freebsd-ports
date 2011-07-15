--- src/network.c.orig	2011-07-14 15:41:32.000000000 +0200
+++ src/network.c	2011-07-14 15:41:37.000000000 +0200
@@ -58,7 +58,9 @@
 #endif
 
 #if HAVE_LIBGCRYPT
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 # include <gcrypt.h>
+#pragma GCC diagnostic warning "-Wdeprecated-declarations"
 GCRY_THREAD_OPTION_PTHREAD_IMPL;
 #endif
 
