--- btcontent.cpp.orig	Sun Feb  1 06:18:07 2004
+++ btcontent.cpp	Fri Feb 13 03:09:22 2004
@@ -8,7 +8,11 @@
 #else
 #include <unistd.h>
 #include <sys/param.h>
+#if defined(HAVE_LIBCRYPT) || defined(HAVE_LIBMD)
+#include <sha.h>
+#elif defined(HAVE_LIBSSL)
 #include <openssl/sha.h>
+#endif
 #endif
 
 #include <time.h>
