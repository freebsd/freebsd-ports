--- src/3rdparty/png++/config.hpp.orig	2009-06-15 02:57:01.000000000 +0400
+++ src/3rdparty/png++/config.hpp	2009-06-22 02:47:55.000000000 +0400
@@ -47,6 +47,11 @@
 #include <machine/endian.h>
 #include <sys/_endian.h>
 
+#elif defined(__FreeBSD__)
+
+#include <machine/endian.h>
+#include <sys/endian.h>
+
 #else
 
 #error Byte-order could not be detected.
