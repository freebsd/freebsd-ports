--- nsprpub/pr/include/md/_freebsd.h.orig	Thu Jan 16 15:09:12 2003
+++ nsprpub/pr/include/md/_freebsd.h	Sun Feb  1 15:21:56 2004
@@ -48,6 +48,12 @@
 #define _PR_SI_ARCHITECTURE "x86"
 #elif defined(__alpha)
 #define _PR_SI_ARCHITECTURE "alpha"
+#elif defined(__sparc__)
+#define _PR_SI_ARCHITECTURE "sparc"
+#elif defined(__ia64__)
+#define _PR_SI_ARCHITECTURE "ia64"
+#elif defined(__amd64__)
+#define _PR_SI_ARCHITECTURE "amd64"
 #else
 #error "Unknown CPU architecture"
 #endif
