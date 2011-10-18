--- hydra.h.orig	2011-10-02 12:06:16.000000000 +0400
+++ hydra.h	2011-10-13 15:08:39.000000000 +0400
@@ -30,10 +30,6 @@
 #endif
 #endif
 
-#ifdef LIBSSH
-#include <libssh/libssh.h>
-#endif
-
 #define OPTION_SSL 1
 
 #define PORT_NOPORT     -1
