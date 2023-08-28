--- pam_innetgr/pam_innetgr.c.orig	2022-02-04 07:04:47.000000000 -0800
+++ pam_innetgr/pam_innetgr.c	2023-08-28 06:57:10.213329000 -0700
@@ -131,7 +131,7 @@
 		return -1;
 #if HAVE_GETDOMAINNAME
 	if (use_getdomainname) {
-		if (xgetname(getdomainname, &domainname)) {
+		if (xgetname((long int *) getdomainname, &domainname)) {
 			_pam_log(LOG_ERR, "getdomainname: %s", strerror(errno));
 		} else if (strcmp (domainname, "(none)") == 0) {
 			free(domainname);
