--- lib/arch/CArchNetworkBSD.cpp.orig	Wed Sep  1 13:52:08 2004
+++ lib/arch/CArchNetworkBSD.cpp	Wed Sep  1 13:52:31 2004
@@ -50,7 +50,6 @@
 #if HAVE_ALLOCA_H
 #	define freea(x_)
 #else
-#	define alloca(x_) malloc(x_)
 #	define freea(x_) free(x_)
 #endif
 
@@ -292,7 +291,7 @@
 
 	// allocate space for translated query
 	struct pollfd* pfd = reinterpret_cast<struct pollfd*>(
-								alloca((1 + num) * sizeof(struct pollfd)));
+								malloc((1 + num) * sizeof(struct pollfd)));
 
 	// translate query
 	for (int i = 0; i < num; ++i) {
