--- src/rping.c.orig	2022-01-14 09:37:12 UTC
+++ src/rping.c
@@ -5,6 +5,10 @@
 
 #include "pingr.h"
 
+#ifdef __FreeBSD__
+#include <netinet/in.h>
+#endif
+
 #ifdef WIN32
 
 #  define WIN32_LEAN_AND_MEAN
