--- scsilib/include/btorder.h.orig	Mon Oct 28 10:15:12 2002
+++ scsilib/include/btorder.h	Mon Oct 28 10:15:29 2002
@@ -1,4 +1,4 @@
-/* @(#)btorder.h	1.14 01/10/09 Copyright 1996 J. Schilling */
+/* @(#)btorder.h	1.15 01/12/09 Copyright 1996 J. Schilling */
 /*
  *	Definitions for Bit and Byte ordering
  *
@@ -66,27 +66,20 @@
 /*
  * Convert byte-order definitions from xconfig.h into our values
  * and verify them.
+ * Note that we cannot use the definitions _LITTLE_ENDIAN and _BIG_ENDIAN
+ * because they are used on IRIX-6.5 with different meaning.
  */
 #if defined(HAVE_C_BIGENDIAN)	&& \
    !defined(WORDS_BIGENDIAN)
 #define	WORDS_LITTLEENDIAN
-#define	_LITTLE_ENDIAN
+/*#define	_LITTLE_ENDIAN*/
 #endif
 
 #if defined(HAVE_C_BIGENDIAN)	&& \
     defined(WORDS_BIGENDIAN)
-#define	_BIG_ENDIAN
+#undef	WORDS_LITTLEENDIAN
+/*#define	_BIG_ENDIAN*/
 #endif
-
-#if	defined(_LITTLE_ENDIAN) && defined(_BIG_ENDIAN)
-/*
- * #error will not work for all compilers (e.g. sunos4)
- * The following line will abort compilation on all compilers
- * if none of the above is defines. And that's  what we want.
- */
-error  Only one of _LITTLE_ENDIAN or _BIG_ENDIAN may be defined
-#endif
-
 
 #if	defined(_BIT_FIELDS_LTOH) || defined(_BIT_FIELDS_HTOL)
 /*
