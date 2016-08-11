--- os.h.orig	2016-06-19 12:41:03.000000000 -0700
+++ os.h	2016-06-21 04:13:47.509485000 -0700
@@ -252,7 +252,9 @@
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
 # if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
+#  ifdef UTMPX_FILE /* GNU extension */
+#   define UTMPFILE	UTMPX_FILE
+#  endif
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -524,6 +526,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
