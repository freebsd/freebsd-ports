--- config.h.orig	2008-05-19 21:59:42.000000000 +0300
+++ config.h	2009-02-17 23:01:51.000000000 +0200
@@ -112,13 +112,13 @@
 
 /* #define SHADOW_NONE		/**/
 /* #define SHADOW_BSD		/* FreeBSD, NetBSD, OpenBSD, BSDI, OS X */
-#define SHADOW_SUN		/* Linux, Solaris, IRIX */
+/* #define SHADOW_SUN		/* Linux, Solaris, IRIX */
 /* #define SHADOW_JFH		/**/
 /* #define SHADOW_MDW		/**/
 /* #define SHADOW_AIX		/* AIX */
 /* #define SHADOW_HPUX		/* HPUX ? */
 
-/* #define PAM			/* Linux PAM or OpenPAM*/
+   #define PAM			/* Linux PAM or OpenPAM*/
 /* #define PAM_OS_X		/* PAM on OS X */
 /* #define PAM_SOLARIS		/* PAM on Solaris other than 2.6 */
 /* #define PAM_SOLARIS_26	/* PAM on Solaris 2.6 */
@@ -200,7 +200,7 @@
  */
 
 #define UNIX_LASTLOG		/**/
-#define HAVE_LASTLOG_H		/**/
+//#define HAVE_LASTLOG_H		/**/
 
 
 /* If NOLOGIN_FILE is defined to the full path name of a file, then the
@@ -245,7 +245,7 @@
  * last).
  */
 
-#define SERVER_UIDS 72		/* user "nobody" */
+#define SERVER_UIDS %%UIDS%%	/* user "nobody" */
 
 
 /* If MIN_UNIX_UID is defined to an integer, logins with uid numbers less than
@@ -257,7 +257,7 @@
  * given value will be accepted).
  */
 
-#define MIN_UNIX_UID 500	/**/
+#define MIN_UNIX_UID %%MINUID%%        /**/
 
 
 /* If IGNORE_CASE is defined, the login given is checked in two different
