--- bsd/krshd.c.orig	2011-07-11 12:31:31.000000000 -0700
+++ bsd/krshd.c	2011-11-16 13:01:40.184757547 -0800
@@ -174,6 +174,10 @@
 #ifdef HAVE_UTMP_H
 #include <utmp.h>
 #endif
+#ifdef HAVE_UTMPX_H
+#include <utmpx.h>
+#define UT_NAMESIZE	sizeof(((struct utmpx *)0)->ut_user)
+#endif
 
 #ifndef UT_NAMESIZE	/* linux defines it directly in <utmp.h> */
 #define	UT_NAMESIZE	sizeof(((struct utmp *)0)->ut_name)
