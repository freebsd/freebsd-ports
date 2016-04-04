--- radwho/radwho.c.orig	2008-12-15 08:03:24 UTC
+++ radwho/radwho.c
@@ -41,7 +41,8 @@ void print_header();
 int want_rad_record(struct radutmp *rt);
 
 /* UTMP stuff. Uses utmpx on svr4 */
-#if defined(__svr4__) || defined(__sgi)  
+#include <sys/param.h>
+#if defined(__svr4__) || defined(__sgi) || (defined(__FreeBSD__) && __FreeBSD_version >= 900007)
 #  include <utmpx.h>
 #  include <sys/fcntl.h>
 #  define utmp utmpx
@@ -49,7 +50,9 @@ int want_rad_record(struct radutmp *rt);
 #  define UT_LINESIZE   32
 #  define UT_HOSTSIZE   257
 #  undef UTMP_FILE
+/*
 #  define UTMP_FILE UTMPX_FILE
+*/
 #  undef WTMP_FILE
 #  define WTMP_FILE WTMPX_FILE
 #else
@@ -60,13 +63,19 @@ int want_rad_record(struct radutmp *rt);
 #  define UT_LINESIZE   32
 #  define UT_HOSTSIZE   64
 #endif
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(bsdi)
+#if (defined(__FreeBSD__) && __FreeBSD_version < 900007) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(bsdi)
 #  ifndef UTMP_FILE
 #    define UTMP_FILE "/var/run/utmp"
 #  endif
 #  define ut_user ut_name
 #endif
 
+#if defined(__FreeBSD__) && __FreeBSD_version >= 900007
+#  define UTMP_FILE "/var/run/utmp"
+#  define ut_name ut_user
+#  define ut_time ut_tv.tv_sec
+#endif
+
 #define P_CONSOLE -1  /* Special radutmp type value for local users */
 
 int  fingerd;             /* Are we run as fingerd */
