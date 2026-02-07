--- compat/gai-errnos.h.orig	2003-05-17 16:39:02 UTC
+++ compat/gai-errnos.h
@@ -10,5 +10,7 @@
 /* for old netdb.h */
 #ifndef EAI_NODATA
 #define EAI_NODATA	1
+#endif
+#ifndef EAI_MEMORY
 #define EAI_MEMORY	2
 #endif
