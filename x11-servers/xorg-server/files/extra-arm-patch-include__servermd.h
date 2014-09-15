--- include/servermd.h.orig	2014-09-10 15:01:49 UTC
+++ include/servermd.h
@@ -104,6 +104,19 @@
 
 #endif                          /* __nds32__ */
 
+#if defined(__FreeBSD__) && defined(__arm__)
+
+#ifdef __BIG_ENDIAN
+#define        IMAGE_BYTE_ORDER        MSBFirst
+#define        BITMAP_BIT_ORDER        MSBFirst
+#else
+#define        IMAGE_BYTE_ORDER        LSBFirst
+#define        BITMAP_BIT_ORDER        LSBFirst
+#endif
+#define        GLYPHPADBYTES           4
+
+#endif /* __FreeBSD__ && __arm__ */
+
 #if defined __hppa__
 
 #define IMAGE_BYTE_ORDER	MSBFirst
@@ -153,7 +166,7 @@
     defined(__sparc__) || defined(__mc68000__)
 
 #if defined(__sparc) || defined(__sparc__)
-#if !defined(sparc)
+#if !defined(sparc) && !defined(__FreeBSD__)
 #define sparc 1
 #endif
 #endif
