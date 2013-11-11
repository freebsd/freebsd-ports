--- compat/stdio.h.orig	2013-07-13 15:22:32.000000000 +0200
+++ compat/stdio.h	2013-11-11 12:56:24.000000000 +0100
@@ -46,7 +46,7 @@
 #endif /* __USE_FILE_OFFSET64 && !__REDIRECT */
 
 // Finally import the <cstdio> stuff we actually use
-#if HAVE_CSTDIO
+#if defined(__cplusplus) && HAVE_CSTDIO
 #include<cstdio>
 #endif
 
