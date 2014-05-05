--- os.h.orig	Tue Jan  8 07:42:33 2002
+++ os.h	Tue Sep  9 17:39:58 2003
@@ -161,7 +161,7 @@
 # define setregid(rgid, egid) setresgid(rgid, egid, -1)
 #endif
 
-#if defined(HAVE_SETEUID) || defined(HAVE_SETREUID)
+#if (defined(HAVE_SETEUID) || defined(HAVE_SETREUID)) && __FreeBSD_version < 500000
 # define USE_SETEUID
 #endif
 
@@ -262,7 +262,11 @@
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
 # if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
+#  ifdef UTMPX_FILE
+#   define UTMPFILE	UTMPX_FILE
+#  else
+#   define UTMPFILE	"/nonexistent"
+#  endif
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -270,7 +274,7 @@
 #  define pututline	pututxline
 #  define setutent	setutxent
 #  define endutent	endutxent
-#  define ut_time	ut_xtime
+#  define ut_time	ut_tv.tv_sec
 # else /* SVR4 */
 #  include <utmp.h>
 # endif /* SVR4 */
