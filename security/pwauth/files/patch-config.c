--- config.h.orig	Thu Oct 14 10:18:19 2004
+++ config.h	Thu Oct 14 10:17:07 2004
@@ -93,11 +93,11 @@
 
 /* #define SHADOW_NONE		/**/
 /* #define SHADOW_BSD		/**/
-#define SHADOW_SUN		/**/
+/* #define SHADOW_SUN		/**/
 /* #define SHADOW_JFH		/**/
 /* #define SHADOW_MDW		/**/
 /* #define SHADOW_AIX		/**/
-/* #define PAM			/**/
+#define PAM			/**/
 /* #define PAM_SOLARIS_26	/**/
 
 
@@ -145,7 +145,7 @@
  * last).
  */
 
-#define SERVER_UIDS 99		/* user "nobody" */
+#define SERVER_UIDS %%UIDS%%	/* user "nobody" */
 
 
 /* If MIN_UNIX_UID is defined to an integer, logins with uid numbers less than
@@ -156,7 +156,7 @@
  * given value will be accepted).
  */
 
-#define MIN_UNIX_UID 500	/**/
+#define MIN_UNIX_UID %%MINUID%%	/**/
 
 
 /* On failed authentications, pwauth will sleep for SLEEP_TIME seconds, using
