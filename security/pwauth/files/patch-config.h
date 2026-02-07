--- config.h.orig	2013-10-04 13:59:08 UTC
+++ config.h
@@ -123,7 +123,7 @@
 
 /* #define SHADOW_NONE		/**/
 /* #define SHADOW_BSD		/* FreeBSD, NetBSD, OpenBSD, BSDI, OS X */
-#define SHADOW_SUN		/* Linux, Solaris, IRIX */
+/* #define SHADOW_SUN		/* Linux, Solaris, IRIX */
 /* #define SHADOW_JFH		/**/
 /* #define SHADOW_MDW		/**/
 /* #define SHADOW_AIX		/* AIX (see also AUTHENTICATE_AIX) */
@@ -131,7 +131,7 @@
 
    /* HIGH-LEVEL OPTIONS */
 
-/* #define PAM			/* Linux PAM or OpenPAM */
+   #define PAM			/* Linux PAM or OpenPAM */
 /* #define PAM_OLD_OS_X		/* PAM on OS X version 10.5 or older */
 /* #define PAM_SOLARIS		/* PAM on Solaris other than 2.6 */
 /* #define PAM_SOLARIS_26	/* PAM on Solaris 2.6 */
@@ -213,8 +213,8 @@
  * uid numbers.
  */
 
-#define UNIX_LASTLOG		/**/
-#define HAVE_LASTLOG_H		/**/
+//#define UNIX_LASTLOG		/**/
+//#define HAVE_LASTLOG_H		/**/
 
 
 /* If NOLOGIN_FILE is defined to the full path name of a file, then the
@@ -279,7 +279,7 @@
  * to change the uid list.
  */
 
-#define SERVER_UIDS 30		/* user "wwwrun" on the author's system */
+#define SERVER_UIDS %%UIDS%%	/**/
 
 
 /* If MIN_UNIX_UID is defined to an integer, logins with uid numbers less than
@@ -291,7 +291,7 @@
  * given value will be accepted).
  */
 
-#define MIN_UNIX_UID 500	/**/
+#define MIN_UNIX_UID %%MINUID%%		/**/
 
 
 /* If IGNORE_CASE is defined, the login given is checked in two different
