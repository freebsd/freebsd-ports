Description: Define the min and max INT constants as needed.
Author: Peter Pentchev <roam@FreeBSD.org>
Forwarded: http://sourceforge.net/mailarchive/message.php?msg_name=20090910102100.GA26539%40straylight.m.ringlet.net
Last-Update: 2009-09-10

--- include/mutils/mincludes.h.orig
+++ include/mutils/mincludes.h
@@ -102,20 +102,28 @@
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
