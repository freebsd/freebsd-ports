--- nsprpub/pr/include/md/_freebsd.h	Thu Jan 16 15:09:12 2003
+++ nsprpub/pr/include/md/_freebsd.h	Sat Dec 13 13:02:49 2003
@@ -48,6 +48,10 @@
 #define _PR_SI_ARCHITECTURE "x86"
 #elif defined(__alpha)
 #define _PR_SI_ARCHITECTURE "alpha"
+#elif defined(__sparc__)
+#define _PR_SI_ARCHITECTURE "sparc"
+#elif defined(__amd64__)
+#define _PR_SI_ARCHITECTURE "amd64"
 #else
 #error "Unknown CPU architecture"
 #endif
