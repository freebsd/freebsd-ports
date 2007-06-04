--- src/sphinxstd.h.orig	Tue May 29 19:50:47 2007
+++ src/sphinxstd.h	Tue May 29 19:52:23 2007
@@ -57,9 +57,7 @@
 #error "Internal 64-bit integer macros already defined."
 #endif
 
-#if __STDC_VERSION__>=199901L || __STDC_VERSION>=199901L || defined(_STDINT_H) || defined(_STDINT_H_)
-#include <stdint.h>
-#else // no stdint.h
+#if !HAVE_STDINT_H
 
 #if defined(_MSC_VER)
 typedef __int64 int64_t;
