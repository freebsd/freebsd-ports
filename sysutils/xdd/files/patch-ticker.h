--- ticker.h.orig	Mon May 29 04:02:17 2006
+++ ticker.h	Mon May 29 04:02:33 2006
@@ -35,7 +35,7 @@
 /* Types */
 /* ----- */
 /* A ticker value */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 typedef unsigned long long tick_t;
 #else
 typedef unsigned __int64  tick_t;
