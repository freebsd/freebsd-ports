--- python/libxml.c.orig	2009-09-24 17:31:59.000000000 +0200
+++ python/libxml.c	2010-10-03 09:34:16.000000000 +0200
@@ -30,7 +30,7 @@
 
 #if (defined(_MSC_VER) || defined(__MINGW32__)) && !defined(vsnprintf)
 #define vsnprintf(b,c,f,a) _vsnprintf(b,c,f,a)
-#elif defined(WITH_TRIO)
+#elif defined(WITH_TRIO) && !defined(vsnprintf)
 #include "trio.h"
 #define vsnprintf trio_vsnprintf
 #endif
