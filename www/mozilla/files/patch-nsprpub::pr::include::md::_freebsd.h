--- nsprpub/pr/include/md/_freebsd.h.orig	Thu Jan 16 15:09:12 2003
+++ nsprpub/pr/include/md/_freebsd.h	Tue Jun 24 23:12:04 2003
@@ -48,6 +48,10 @@
 #define _PR_SI_ARCHITECTURE "x86"
 #elif defined(__alpha)
 #define _PR_SI_ARCHITECTURE "alpha"
+#elif defined(__sparc__)
+#define _PR_SI_ARCHITECTURE "sparc"
+#elif defined(__ia64__)
+#define _PR_SI_ARCHITECTURE "ia64"
 #else
 #error "Unknown CPU architecture"
 #endif
