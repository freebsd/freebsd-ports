diff -urN -x .svn ../../branches/mhash-dist/include/mutils/mincludes.h ./include/mutils/mincludes.h
--- ../../branches/mhash-dist/include/mutils/mincludes.h	2008-01-16 02:34:17.000000000 +0200
+++ ./include/mutils/mincludes.h	2008-01-16 02:35:49.000000000 +0200
@@ -100,20 +100,28 @@
 #include <stdint.h>
 #endif
 
-#if !defined(INT_MAX)
-#define INT_MAX ((int) (~0U>>1))
-#endif
-
-#if !defined(MAXINT)
-#define MAXINT INT_MAX
-#endif
+#ifndef	INT_MAX
+#ifdef	INTMAX
+#define	INT_MAX	INTMAX
+#else	/* INTMAX */
+#ifdef	MAXINT
+#define	INT_MAX	MAXINT
+#else	/* MAXINT */
+#error	Cannot find either INT_MAX, INTMAX, or MAXINT
+#endif	/* MAXINT */
+#endif	/* INTMAX */
+#endif	/* INT_MAX */
 
-#if !defined(INT_MIN)
-#define INT_MIN (-INT_MAX - 1)
-#endif
-
-#if !defined(MININT)
-#define MININT INT_MIN
-#endif
+#ifndef	INT_MIN
+#ifdef	INTMIN
+#define	INT_MIN	INTMIN
+#else	/* INTMIN */
+#ifdef	MININT
+#define	INT_MIN	MININT
+#else	/* MININT */
+#error	Cannot find either INT_MIN, INTMIN, or MININT
+#endif	/* MININT */
+#endif	/* INTMIN */
+#endif	/* INT_MIN */
 
 #endif
