--- libgnomeprint/ttsubset/sft.h.orig	Thu Jul  1 13:18:38 2004
+++ libgnomeprint/ttsubset/sft.h	Thu Jul  1 13:20:14 2004
@@ -103,7 +103,7 @@
 #endif
 #endif
 
-#ifdef __i386
+#if defined(__i386) || defined(__alpha__)
 #ifndef G_LITTLE_ENDIAN
 #define G_LITTLE_ENDIAN
 #endif
