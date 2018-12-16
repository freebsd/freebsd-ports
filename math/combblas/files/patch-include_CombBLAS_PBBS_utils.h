--- include/CombBLAS/PBBS/utils.h.orig	2018-12-16 06:18:22 UTC
+++ include/CombBLAS/PBBS/utils.h
@@ -26,7 +26,7 @@
 #include <algorithm>
 #include <limits.h>
 
-#if defined(__APPLE__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #define PTCMPXCH "  cmpxchgl %2,%1\n"
 #else
 #define PTCMPXCH "  cmpxchgq %2,%1\n"
