--- src/pam_fprint.c.orig	2009-01-08 21:31:21 UTC
+++ src/pam_fprint.c
@@ -18,6 +18,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <pwd.h>
@@ -27,6 +28,7 @@
 
 #define PAM_SM_AUTH
 #include <security/pam_modules.h>
+#include <security/pam_appl.h>
 
 static int send_info_msg(pam_handle_t *pamh, char *msg)
 {
@@ -41,10 +43,10 @@ static int send_info_msg(pam_handle_t *pamh, char *msg
 
     r = pam_get_item(pamh, PAM_CONV, (const void **) &pc);
 	if (r != PAM_SUCCESS)
-		return;
+		return r;
 
 	if (!pc || !pc->conv)
-		return;
+		return PAM_BUF_ERR;
 
 	return pc->conv(1, &msgp, &resp, pc->appdata_ptr);
 }
@@ -62,10 +64,10 @@ static int send_err_msg(pam_handle_t *pamh, char *msg)
 
     r = pam_get_item(pamh, PAM_CONV, (const void **) &pc);
 	if (r != PAM_SUCCESS)
-		return;
+		return r;
 
 	if (!pc || !pc->conv)
-		return;
+		return PAM_BUF_ERR;
 
 	return pc->conv(1, &msgp, &resp, pc->appdata_ptr);
 }
@@ -102,7 +104,7 @@ static struct fp_print_data **find_dev_and_prints(stru
 	struct fp_print_data **gallery;
 
 	/* TODO: add device selection */
-	while (print = prints[i++]) {
+	while ((print = prints[i++])) {
 		if (!ddev) {
 			ddev = fp_dscv_dev_for_dscv_print(ddevs, print);
 			driver_id = fp_dscv_print_get_driver_id(print);
@@ -133,7 +135,7 @@ static struct fp_print_data **find_dev_and_prints(stru
 	}
 	
 	i = 0, j = 0;
-	while (print = prints[i++]) {
+	while ((print = prints[i++])) {
 		driver_id_cur = fp_dscv_print_get_driver_id(print);
 		if (driver_id_cur == driver_id) {
 			err = fp_print_data_from_dscv_print(print, & (gallery[j]));
