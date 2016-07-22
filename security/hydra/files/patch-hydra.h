--- hydra.h.orig	2016-06-16 14:57:15 UTC
+++ hydra.h
@@ -31,10 +31,6 @@
 #endif
 #endif
 
-#ifdef LIBSSH
-#include <libssh/libssh.h>
-#endif
-
 #ifdef HAVE_ZLIB
 #include <zlib.h>
 #endif
