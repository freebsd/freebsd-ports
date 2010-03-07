--- ./src/include/sysutmp.h.orig	2009-12-30 10:44:35.000000000 -0500
+++ ./src/include/sysutmp.h	2010-03-06 09:32:13.075571526 -0500
@@ -30,7 +30,7 @@
 #  define UT_NAMESIZE	32
 #  define UT_LINESIZE	32
 #  define UT_HOSTSIZE	257
-#ifdef hpux
+#if defined(hpux) || defined(__FreeBSD__)
 #  define ut_name ut_user
 #endif
 #else
@@ -43,7 +43,7 @@
 #  define UT_HOSTSIZE	64
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(bsdi) || defined(__OpenBSD__) || defined(__APPLE__)
+#if (defined(__FreeBSD__) && !defined(HAVE_UTMPX_H)) || defined(__NetBSD__) || defined(bsdi) || defined(__OpenBSD__) || defined(__APPLE__)
 #  ifndef UTMP_FILE
 #    define UTMP_FILE "/var/run/utmp"
 #  endif
