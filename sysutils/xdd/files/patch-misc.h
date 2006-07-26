--- misc.h.orig	Mon May 29 04:04:19 2006
+++ misc.h	Mon May 29 04:12:05 2006
@@ -35,7 +35,7 @@
 /* -------- */
 /* Includes */
 /* -------- */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #ifndef NDEBUG /* These are only needed if Assert() expands to something */
 #include <stdio.h> /* fprintf(), stderr */
 #include <unistd.h> /* pause() */
@@ -60,7 +60,7 @@
 /* --------- */
 /* Constants */
 /* --------- */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #define MILLION  1000000LL /* 10^6, as opposed to 2^20 */
 #define BILLION  1000000000LL /* 10^9, as opposed to 2^30 */
 #define TRILLION 1000000000000LL /* 10^12, as opposed to 2^40 */
@@ -77,7 +77,7 @@
 #ifndef LLONG_MIN
 #define LLONG_MIN (-LLONG_MAX - 1LL)
 #endif
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 #ifndef LONGLONG_MIN
 #define LONGLONG_MIN LLONG_MIN
 #endif
