--- btfiles.cpp.orig	Sun Feb  1 06:33:16 2004
+++ btfiles.cpp	Fri Feb 13 03:10:57 2004
@@ -8,7 +8,11 @@
 #include <unistd.h>
 #include <dirent.h>
 #include <sys/param.h>
+#if defined(HAVE_LIBCRYPT) || defined(HAVE_LIBMD)
+#include <sha.h>
+#elif defined(HAVE_LIBSSL)
 #include <openssl/sha.h>
+#endif
 #endif
 
 #include <time.h>
