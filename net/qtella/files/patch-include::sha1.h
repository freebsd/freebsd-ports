--- include/sha1.h.orig	Wed Oct  2 08:27:57 2002
+++ include/sha1.h	Mon Jan 27 17:24:25 2003
@@ -5,7 +5,7 @@
 extern "C" {
 #endif
 
-#include <stdint.h>
+#include <inttypes.h>
 /*
  * If you do not have the ISO standard stdint.h header file, then you
  * must typdef the following:
@@ -27,6 +27,11 @@
 };
 #endif
 #define SHA1HashSize 20
+
+#include <osreldate.h>
+#if __FreeBSD_version < 500000
+typedef uint32_t int_least16_t;
+#endif
 
 /*
  *  This structure will hold context information for the SHA-1
