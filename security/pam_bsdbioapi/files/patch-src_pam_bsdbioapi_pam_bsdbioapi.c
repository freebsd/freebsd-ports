--- src/pam_bsdbioapi/pam_bsdbioapi.c	Thu Feb 23 06:15:13 2006
+++ src/pam_bsdbioapi/pam_bsdbioapi.c.orig	Sun Dec 10 06:26:57 2006
@@ -215,7 +215,7 @@
     int argc, const char *argv[])
 {
 	const char *user, *bsp_id, *dbid, *conf, *msgfile;
-	int error, pam_retval = PAM_AUTH_ERR;
+	int error, pam_retval = PAM_AUTH_ERR, skip_unenrolled;
 	BioAPI_HANDLE *handle;
 	struct birdb_rec keyrec, **recs;
 	struct birdb_mod *bm;
@@ -241,9 +241,10 @@
 
 	conf = DEFCONFPATH; 
 	msgfile = NULL;
+	skip_unenrolled = 0;
 
 	optind = 2;
-	while ((opt = getopt(argc, (char **)argv, "m:f:")) != -1) {
+	while ((opt = getopt(argc, (char **)argv, "m:f:s")) != -1) {
 		switch (opt) {
 		case 'm':
 			msgfile = argv[optind - 1];
@@ -253,6 +254,9 @@
 			conf = argv[optind - 1];
 			PAM_LOG("Got birdb configuration file: %s", conf);
 			break;
+		case 's':
+			skip_unenrolled = 1;
+			break;
 		}
 	}
 
@@ -271,7 +275,6 @@
 	PAM_LOG("Got user: %s", user);
 
 	setuid(euid);
-	pam_info(pamh, "Initiating biometric authentication..."); 
 
 	error = bioapi_init();
 	if (error)
@@ -312,7 +315,8 @@
 
 	keyrec.br_key = (char *)user;
 	recs = birdb_backend_get(bm, bmh, &keyrec);
-	if (recs != NULL) {
+	if (recs != NULL && (!skip_unenrolled || recs[0] != NULL)) {
+		pam_info(pamh, "Initiating biometric authentication..."); 
 		handle = bioapi_attach_bsp(bsp_id);
 		if (handle == NULL) {
 			PAM_VERBOSE_ERROR("Failed to attach the selected BSP");
