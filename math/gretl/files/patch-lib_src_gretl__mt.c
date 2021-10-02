- https://sourceforge.net/p/gretl/bugs/251/

--- lib/src/gretl_mt.c.orig	2021-10-02 09:01:37 UTC
+++ lib/src/gretl_mt.c
@@ -27,6 +27,8 @@
 # include <omp.h>
 #endif
 
+#include <unistd.h> // for sysconf
+
 /* for processors count */
 #if defined(WIN32)
 # include <windows.h>
