--- ./src/main.h.orig	2013-10-29 13:38:10.000000000 +0000
+++ ./src/main.h	2014-01-18 23:12:20.871138275 +0000
@@ -16,7 +16,6 @@
 #ifdef __WXMSW__
 #include <io.h> /* for _commit */
 #elif !defined(MAC_OSX)
-#include <sys/prctl.h>
 #endif
 
 class CBlock;
