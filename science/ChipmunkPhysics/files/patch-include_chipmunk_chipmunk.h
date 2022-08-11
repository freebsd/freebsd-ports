--- include/chipmunk/chipmunk.h.orig	2015-08-29 18:44:21 UTC
+++ include/chipmunk/chipmunk.h
@@ -29,6 +29,10 @@
 	// For alloca().
 	#include <malloc.h>
 	#define CP_EXPORT __declspec(dllexport)
+#elif defined(__DragonFly__) || defined(__FreeBSD__) \
+	|| defined(__NetBSD__) || defined(__OpenBSD__) \
+	// alloca() is already included in <stdlib.h>
+	#define CP_EXPORT
 #else
 	#include <alloca.h>
 	#define CP_EXPORT
