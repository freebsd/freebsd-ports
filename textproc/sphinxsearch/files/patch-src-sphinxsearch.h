--- src/sphinxstd.h.orig	Sun Apr 15 20:16:11 2007
+++ src/sphinxstd.h	Sun Apr 15 20:17:25 2007
@@ -57,7 +57,7 @@
 #error "Internal 64-bit integer macros already defined."
 #endif
 
-#if __STDC_VERSION__>=199901L || __STDC_VERSION>=199901L || defined(_STDINT_H) || defined(_STDINT_H_)
+#if __STDC_VERSION__>=199901L || __STDC_VERSION>=199901L || defined(_STDINT_H) || defined(_STDINT_H_) || defined(_SYS_STDINT_H_)
 #include <stdint.h>
 #else // no stdint.h
 
