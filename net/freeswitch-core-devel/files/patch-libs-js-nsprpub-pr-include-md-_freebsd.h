--- libs/js/nsprpub/pr/include/md/_freebsd.h
+++ libs/js/nsprpub/pr/include/md/_freebsd.h
@@ -57,7 +57,13 @@
 #define _PR_SI_ARCHITECTURE "ia64"
 #elif defined(__amd64__)
 #define _PR_SI_ARCHITECTURE "amd64"
+#elif defined(__arm__)
+#define _PR_SI_ARCHITECTURE "arm"
+#elif defined(__mips__)
+#define _PR_SI_ARCHITECTURE "mips"
+
 #else
+
 #error "Unknown CPU architecture"
 #endif
 #if defined(__ELF__)
