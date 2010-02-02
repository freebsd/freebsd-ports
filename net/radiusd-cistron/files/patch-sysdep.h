--- src/sysdep.h.orig	2003-06-04 17:45:28.000000000 +0200
+++ src/sysdep.h	2010-01-27 07:21:57.000000000 +0100
@@ -50,6 +50,10 @@
 # include        <malloc.h>
 #endif  /* FreeBSD */
 
+#if defined(__FreeBSD__)
+# include        <osreldate.h>
+#endif  /* FreeBSD */
+
 #if defined(aix)
 #include	<sys/select.h>
 #include	<strings.h>
@@ -67,8 +71,17 @@
 #  define UT_LINESIZE	32
 #  define UT_HOSTSIZE	257
 #else
+#if __FreeBSD_version >= 900007
+#  include <utmpx.h>
+#  define utmp utmpx
+#  define UT_NAMESIZE	32
+#  define UT_LINESIZE	16
+#  define UT_HOSTSIZE	128
+#  define ut_name ut_user
+#else
 #  include <utmp.h>
 #endif
+#endif
 #ifdef __osf__
 #  define UT_NAMESIZE	32
 #  define UT_LINESIZE	32
@@ -83,7 +96,7 @@
 #    define __hpux__
 #  endif
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(bsdi)
+#if (defined(__FreeBSD__) && __FreeBSD_version < 900007 ) || defined(__NetBSD__) || defined(bsdi)
 #  ifndef UTMP_FILE
 #    define UTMP_FILE "/var/run/utmp"
 #  endif
