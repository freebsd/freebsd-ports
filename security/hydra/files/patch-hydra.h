--- hydra.h.orig	2019-01-02 12:38:23 UTC
+++ hydra.h
@@ -38,10 +38,6 @@
   #endif
 #endif
 
-#ifdef LIBSSH
-  #include <libssh/libssh.h>
-#endif
-
 #ifdef HAVE_ZLIB
   #include <zlib.h>
 #endif
