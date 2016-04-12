--- src/nss-pgsql.h.orig	2015-12-21 07:47:28 UTC
+++ src/nss-pgsql.h
@@ -15,9 +15,30 @@
 
 #  include <pwd.h>
 #  include <grp.h>
+#ifdef HAVE_SHADOW_H
 #  include <shadow.h>
+#endif
 #  include <sys/types.h>
 
+#ifndef HAVE_SHADOW_H
+/* Structure of the password file.  */
+struct spwd
+  {
+    char *sp_namp;		/* Login name.  */
+    char *sp_pwdp;		/* Encrypted password.  */
+    long int sp_lstchg;		/* Date of last change.  */
+    long int sp_min;		/* Minimum number of days between changes.  */
+    long int sp_max;		/* Maximum number of days between changes.  */
+    long int sp_warn;		/* Number of days to warn user to change
+				   the password.  */
+    long int sp_inact;		/* Number of days the account may be
+				   inactive.  */
+    long int sp_expire;		/* Number of days since 1970-01-01 until
+				   account expires.  */
+    unsigned long int sp_flag;	/* Reserved.  */
+  };
+#endif
+
 #define CFGFILE SYSCONFDIR"/nss-pgsql.conf"
 #define CFGROOTFILE SYSCONFDIR"/nss-pgsql-root.conf"
 
