--- src/pam_fprint_enroll.c~	2009-01-08 15:31:21.000000000 -0600
+++ src/pam_fprint_enroll.c	2011-11-13 02:15:43.976691333 -0600
@@ -47,7 +47,7 @@ static struct fp_dscv_dev *discover_devi
 	struct fp_dscv_dev *ddev = NULL;
 	int i;
 
-	for (i = 0; ddev = discovered_devs[i]; i++) {
+	for (i = 0; (ddev = discovered_devs[i]); i++) {
 		struct fp_driver *drv = fp_dscv_dev_get_driver(ddev);
 		printf("Found device claimed by %s driver\n",
 			fp_driver_get_full_name(drv));
