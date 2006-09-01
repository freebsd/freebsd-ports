--- pam_abl.h.orig	Wed Oct 12 21:22:27 2005
+++ pam_abl.h	Sat Jan 14 19:25:44 2006
@@ -51,6 +51,7 @@
 #define __PAM_ABL_H
 
 #include <security/pam_modules.h>
+#include <security/pam_appl.h>
 #include <db.h>
 
 #include <ctype.h>
@@ -74,7 +75,7 @@
 /* User purge time in seconds */
 #define USER_PURGE  (HOURSECS * 24)
 
-#define CONFIG "/etc/security/pam_abl.conf"
+#define CONFIG "%%ETCPREFIX%%/etc/pam_abl.conf"
 
 typedef struct abl_string {
     struct abl_string *link;
