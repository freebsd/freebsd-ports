--- nsprpub/pr/include/md/_freebsd.h.orig	Sat Nov 15 23:36:13 2003
+++ nsprpub/pr/include/md/_freebsd.h	Mon Feb  9 22:24:39 2004
@@ -50,6 +50,10 @@
 #define _PR_SI_ARCHITECTURE "alpha"
 #elif defined(__sparc__)
 #define _PR_SI_ARCHITECTURE "sparc"
+#elif defined(__ia64__)
+#define _PR_SI_ARCHITECTURE "ia64"
+#elif defined(__amd64__)
+#define _PR_SI_ARCHITECTURE "amd64"
 #else
 #error "Unknown CPU architecture"
 #endif
