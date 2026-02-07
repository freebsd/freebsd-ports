--- ports/bsd/bip6.c.orig	2025-06-28 19:56:23 UTC
+++ ports/bsd/bip6.c
@@ -22,8 +22,8 @@
 #endif
 #include "bacport.h"
 
-#if defined(__APPLE__) || defined(__darwin__)
-/* OSX seems not to define these. */
+#if defined(__APPLE__) || defined(__darwin__) || defined(__FreeBSD__)
+/* FreeBSD 13.x and OSX seems not to define these. */
 #ifndef s6_addr16
 #define s6_addr16 __u6_addr.__u6_addr16
 #endif
