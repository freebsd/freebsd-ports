--- hydra.h.orig	2020-07-29 07:36:37 UTC
+++ hydra.h
@@ -44,10 +44,6 @@
 #endif
 #endif
 
-#ifdef LIBSSH
-#include <libssh/libssh.h>
-#endif
-
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif
