--- mediastreamer2/src/dsptools.c.orig	2009-09-19 14:00:35.000000000 -0300
+++ mediastreamer2/src/dsptools.c	2009-09-19 14:01:21.000000000 -0300
@@ -56,10 +56,6 @@
 
 #ifdef HAVE_ALLOCA_H
 #include <alloca.h>
-#else
-#if !defined(__APPLE__)
-#include <malloc.h>
-#endif
 #endif
 
 #define ALLOC(var,size,type) var = alloca(sizeof(type)*(size))
