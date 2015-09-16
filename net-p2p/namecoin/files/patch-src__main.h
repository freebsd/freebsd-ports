--- src/main.h.orig	2014-12-18 14:47:02 UTC
+++ src/main.h
@@ -17,7 +17,6 @@
 #ifdef __WXMSW__
 #include <io.h> /* for _commit */
 #elif !defined(MAC_OSX)
-#include <sys/prctl.h>
 #endif
 
 class CBlock;
