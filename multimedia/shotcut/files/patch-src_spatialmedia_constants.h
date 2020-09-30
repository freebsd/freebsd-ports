--- src/spatialmedia/constants.h.orig	2020-09-20 19:10:00 UTC
+++ src/spatialmedia/constants.h
@@ -19,6 +19,7 @@
 
 #include <stdint.h>
 #include <string>
+#include <sys/param.h>
 
 #include <QtEndian>
 #if defined(Q_OS_WIN) || defined(Q_OS_MAC)
@@ -34,6 +35,8 @@
 #  define htole64(x) qtoLittleEndian(x)
 #  define be64toh(x) qFromBigEndian(x)
 #  define le64toh(x) qFromLittleEndian(x)
+#elif defined(__FreeBSD__)
+# include <sys/endian.h>
 #else
 #  include <endian.h>
 #endif
