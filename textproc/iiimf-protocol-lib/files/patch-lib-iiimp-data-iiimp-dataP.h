--- data/iiimp-dataP.h.orig	Tue Aug 24 13:38:12 2004
+++ data/iiimp-dataP.h	Wed Sep  8 23:04:47 2004
@@ -14,8 +14,13 @@
 extern "C" {
 #endif
 
+#if defined(BIG_ENDIAN) && defined(BYTE_ORDER) && (BIG_ENDIAN==BYTE_ORDER)
+#define _IT_IS_BIG_ENDIAN_LALALA_
+#elif defined(_BIG_ENDIAN) && defined(_BYTE_ORDER) && (_BIG_ENDIAN==_BYTE_ORDER)
+#define _IT_IS_BIG_ENDIAN_LALALA_
+#endif
 
-#if defined(_BIG_ENDIAN) || defined(WORDS_BIGENDIAN)
+#if defined(_IT_IS_BIG_ENDIAN_LALALA_)
 
 #define	GETU16(n, r, p, b)	(((n) = ((0 == (b)) ? \
 					 (((*((uchar_t *)(p + 0))) << 8) + \
@@ -113,7 +118,7 @@
 
 #else /* !(_BIG_ENDIAN || WORDS_BIGENDIAN) */
 
-#define	GET_SCOPE_FOR_HOTKEY(n, p, b) \	
+#define	GET_SCOPE_FOR_HOTKEY(n, p, b) \
                                    if (0 == (b)) { \
                                      if ((*((uchar_t *)(p + 1)) & 0x80)) \
                                        (n) = 1; \
