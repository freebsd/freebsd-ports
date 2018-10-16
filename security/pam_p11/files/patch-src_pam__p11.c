--- src/pam_p11.c.orig	2018-10-16 10:00:15 UTC
+++ src/pam_p11.c
@@ -53,7 +53,7 @@
 #include <security/pam_ext.h>
 #else
 #define pam_syslog(handle, level, msg...) syslog(level, ## msg)
-static int pam_vprompt(pam_handle_t *pamh, int style, char **response,
+int pam_vprompt(const pam_handle_t *pamh, int style, char **response,
 		const char *fmt, va_list args)
 {
 	int r = PAM_CRED_INSUFFICIENT;
