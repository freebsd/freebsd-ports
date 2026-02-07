--- sash.h.orig	Mon Jul 22 00:05:17 2002
+++ sash.h	Fri Sep  3 15:27:16 2004
@@ -18,7 +18,7 @@
 #include <time.h>
 #include <ctype.h>
 
-#if __OpenBSD__
+#if __FreeBSD__ || __OpenBSD__
 #include <sys/param.h>
 #endif
 
