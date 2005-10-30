--- config.h.orig	Wed Sep 29 01:07:18 2004
+++ config.h	Sun Oct 30 13:49:52 2005
@@ -106,13 +106,13 @@
 
 /* #define SHADOW_NONE		/**/
 /* #define SHADOW_BSD		/* FreeBSD, NetBSD, OpenBSD, BSDI */
-#define SHADOW_SUN		/* Linux, Solaris, IRIX */
+/* #define SHADOW_SUN		/* Linux, Solaris, IRIX */
 /* #define SHADOW_JFH		/**/
 /* #define SHADOW_MDW		/**/
 /* #define SHADOW_AIX		/* AIX */
 /* #define SHADOW_HPUX		/* HPUX ? */
 
-/* #define PAM			/* Linux PAM or OpenPAM*/
+   #define PAM			/* Linux PAM or OpenPAM*/
 /* #define PAM_SOLARIS		/* PAM on Solaris other than 2.6 */
 /* #define PAM_SOLARIS_26	/* PAM on Solaris 2.6 */
 /* #define LOGIN_CONF_OPENBSD	/**/
@@ -193,7 +193,7 @@
  */
 
 #define UNIX_LASTLOG		/**/
-#define HAVE_LASTLOG_H		/**/
+//#define HAVE_LASTLOG_H		/**/
 
 
 /* If NOLOGIN_FILE is defined to the full path name of a file, then the
@@ -238,7 +238,7 @@
  * last).
  */
 
-#define SERVER_UIDS 72		/* user "nobody" */
+#define SERVER_UIDS %%UIDS%%	/* user "www" */
 
 
 /* If MIN_UNIX_UID is defined to an integer, logins with uid numbers less than
@@ -250,7 +250,7 @@
  * given value will be accepted).
  */
 
-#define MIN_UNIX_UID 500	/**/
+#define MIN_UNIX_UID 1000	/**/
 
 
 /* If IGNORE_CASE is defined, the login given is checked in two different
