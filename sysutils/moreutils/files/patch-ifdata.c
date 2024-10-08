--- ifdata.c.orig	2024-02-25 19:47:01 UTC
+++ ifdata.c
@@ -18,7 +18,7 @@
 	#include <net/if.h>
 #endif
 
-#if defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 	#define s6_addr16 __u6_addr.__u6_addr16
 	#include <net/if.h>
 #endif
