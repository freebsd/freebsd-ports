--- src/pam_fprint_enroll.c.orig	2009-01-08 21:31:21 UTC
+++ src/pam_fprint_enroll.c
@@ -26,7 +26,7 @@
 #include <unistd.h>
 #include <getopt.h>
 
-#include <libfprint/fprint.h>
+#include <fprint.h>
 
 static const char *finger_names[] = {
 	[LEFT_THUMB] = "Left Thumb",
@@ -47,7 +47,7 @@ static struct fp_dscv_dev *discover_device(struct fp_d
 	struct fp_dscv_dev *ddev = NULL;
 	int i;
 
-	for (i = 0; ddev = discovered_devs[i]; i++) {
+	for (i = 0; (ddev = discovered_devs[i]); i++) {
 		struct fp_driver *drv = fp_dscv_dev_get_driver(ddev);
 		printf("Found device claimed by %s driver\n",
 			fp_driver_get_full_name(drv));
