--- src/rapiclient.cpp.orig	2008-04-15 11:35:52.000000000 +0200
+++ src/rapiclient.cpp	2008-04-15 11:37:50.000000000 +0200
@@ -20,6 +20,11 @@
 #include <errno.h>
 #include <synce.h>
 
+#if defined(__FreeBSD__) && defined(__sparc64__)
+#include <sys/endian.h>
+#define bswap_16 bswap16
+#define bswap_32 bswap32
+#endif
 
 using namespace std;
 
