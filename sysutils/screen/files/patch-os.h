--- os.h.orig	2014-04-26 03:58:35.000000000 -0700
+++ os.h	2014-04-29 19:16:31.730773575 -0700
@@ -252,7 +252,11 @@
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
@@ -260,7 +264,7 @@
 #  define pututline	pututxline
 #  define setutent	setutxent
 #  define endutent	endutxent
-#  define ut_time	ut_xtime
+#  define ut_time	ut_tv.tv_sec
 # else /* SVR4 */
 #  include <utmp.h>
 # endif /* SVR4 */
@@ -524,6 +528,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
