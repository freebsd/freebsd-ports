--- src/providers/ldap/ldap_auth.c.orig	2023-05-05 08:11:07 UTC
+++ src/providers/ldap/ldap_auth.c
@@ -37,7 +37,6 @@
 #include <sys/time.h>
 #include <strings.h>
 
-#include <shadow.h>
 #include <security/pam_modules.h>
 
 #include "util/util.h"
@@ -51,6 +50,22 @@
 
 #define LDAP_PWEXPIRE_WARNING_TIME 0
 
+struct spwd
+{
+  char *sp_namp;              /* Login name.  */
+  char *sp_pwdp;              /* Encrypted password.  */
+  long int sp_lstchg;         /* Date of last change.  */
+  long int sp_min;            /* Minimum number of days between changes.  */
+  long int sp_max;            /* Maximum number of days between changes.  */
+  long int sp_warn;           /* Number of days to warn user to change
+                                the password.  */
+  long int sp_inact;          /* Number of days the account may be
+                                inactive.  */
+  long int sp_expire;         /* Number of days since 1970-01-01 until
+                                account expires.  */
+  unsigned long int sp_flag;  /* Reserved.  */
+};
+
 static errno_t add_expired_warning(struct pam_data *pd, long exp_time)
 {
     int ret;
@@ -96,9 +111,9 @@ static errno_t check_pwexpire_kerberos(const char *exp
     }
 
     DEBUG(SSSDBG_TRACE_ALL,
-          "Time info: tzname[0] [%s] tzname[1] [%s] timezone [%ld] "
-          "daylight [%d] now [%"SPRItime"] expire_time [%"SPRItime"].\n",
-          tzname[0], tzname[1], timezone, daylight, now, expire_time);
+          "Time info: tzname[0] [%s] tzname[1] [%s] "
+          "now [%"SPRItime"] expire_time [%"SPRItime"].\n",
+          tzname[0], tzname[1], now, expire_time);
 
     if (expire_time == 0) {
         /* Used by the MIT LDAP KDB plugin to indicate "never" */
