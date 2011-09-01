--- bsd/krlogind.c.orig	2009-11-21 12:29:19.000000000 -0800
+++ bsd/krlogind.c	2011-08-31 21:05:10.318698837 -0700
@@ -236,6 +236,9 @@
 #ifdef HAVE_UTMP_H
 #include <utmp.h>
 #endif
+#ifdef HAVE_UTMPX_H
+#include <utmpx.h>
+#endif
 
 int non_privileged = 0; /* set when connection is seen to be from */
 			/* a non-privileged port */
@@ -275,8 +278,13 @@
 #define MAX_PROG_NAME 16
 
 #ifndef UT_NAMESIZE	/* linux defines it directly in <utmp.h> */
+#ifdef HAVE_UTMP_H
 #define	UT_NAMESIZE	sizeof(((struct utmp *)0)->ut_name)
 #endif
+#ifdef HAVE_UTMPX_H
+#define	UT_NAMESIZE	sizeof(((struct utmpx *)0)->ut_user)
+#endif
+#endif
 
 #if HAVE_ARPA_NAMESER_H
 #include <arpa/nameser.h>
