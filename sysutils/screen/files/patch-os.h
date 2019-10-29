--- os.h.orig	2019-10-01 15:08:00.000000000 -0700
+++ os.h	2019-10-28 19:37:41.585526000 -0700
@@ -250,9 +250,11 @@
 #endif
 
 #if defined(UTMPOK) || defined(BUGGYGETLOGIN)
-# if defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)
+# if (defined(SVR4) && !defined(DGUX) && !defined(__hpux) && !defined(linux)) || defined(__FreeBSD_version)
 #  include <utmpx.h>
-#  define UTMPFILE	UTMPX_FILE
+#  ifdef UTMPX_FILE /* GNU extension */
+#   define UTMPFILE	UTMPX_FILE
+#  endif
 #  define utmp		utmpx
 #  define getutent	getutxent
 #  define getutid	getutxid
@@ -507,7 +509,7 @@
  */
 
 #ifndef TERMCAP_BUFSIZE
-# define TERMCAP_BUFSIZE 2048
+# define TERMCAP_BUFSIZE 1023
 #endif
 
 #ifndef MAXPATHLEN
@@ -524,6 +526,6 @@
 /* Changing those you won't be able to attach to your old sessions
  * when changing those values in official tree don't forget to bump
  * MSG_VERSION */
-#define MAXTERMLEN	32
+#define MAXTERMLEN	63
 #define MAXLOGINLEN	256
 
