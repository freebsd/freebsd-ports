--- unixlib/passwd.C.orig	Sat Jun 16 19:56:46 2001
+++ unixlib/passwd.C	Sun Jun 17 23:24:20 2001
@@ -10,6 +10,9 @@
 #include <grp.h>
 #include <stdlib.h>
 #include <string.h>
+#ifdef PAM_DEBUG
+#include <syslog.h>
+#endif
 
 #ifdef HAVE_CRYPT_H
 #include <crypt.h>
@@ -70,6 +73,11 @@
     int ret;
     pam_handle_t *pah;
     int pam_status = PAM_SUCCESS;     
+
+#ifdef PAM_DEBUG
+    openlog("dkimap4", LOG_PID, LOG_MAIL);
+    syslog(LOG_INFO, "DKIMAP authentication attempt: user=%s passwd=%s uid=%d program=%s", username, passwd, uid, program);
+#endif
 
     static struct pam_conv pac = {
         pam_conv_func,
