--- nsprpub/pr/include/md/_freebsd.h.orig	Sat Nov 15 18:36:13 2003
+++ nsprpub/pr/include/md/_freebsd.h	Sun Dec 14 11:40:08 2003
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
