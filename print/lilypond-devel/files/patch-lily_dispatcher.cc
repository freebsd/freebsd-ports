--- lily/dispatcher.cc.orig	2021-11-28 13:46:28 UTC
+++ lily/dispatcher.cc
@@ -23,8 +23,10 @@
 #include "warn.hh"
 #include "lily-imports.hh"
 
-#ifdef __MINGW32__
+#if defined __MINGW32__
 #include <malloc.h>
+#elif defined __FreeBSD__
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
