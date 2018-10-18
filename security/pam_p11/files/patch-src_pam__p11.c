--- src/pam_p11.c.orig	2018-05-04 14:52:04 UTC
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
@@ -549,7 +549,7 @@ static int key_find(pam_handle_t *pamh, 
 	return 0;
 }
 
-static int randomize(pam_handle_t *pamh, unsigned char *r, unsigned int r_len)
+static int randomize(pam_handle_t *pamh, unsigned char *r, int r_len)
 {
 	int ok = 0;
 	int fd = open("/dev/urandom", O_RDONLY);
