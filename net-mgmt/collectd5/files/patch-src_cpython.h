--- src/cpython.h.orig	2020-07-20 09:50:14 UTC
+++ src/cpython.h
@@ -26,7 +26,7 @@
 
 /* Some python versions don't include this by default. */
 
-#include <longintrepr.h>
+#include <python3.11/cpython/longintrepr.h>
 
 /* These two macros are basically Py_BEGIN_ALLOW_THREADS and
  * Py_BEGIN_ALLOW_THREADS
