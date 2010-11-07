--- usr/lib/pkcs11/common/new_host.c.orig	2010-07-29 21:28:41.000000000 +0900
+++ usr/lib/pkcs11/common/new_host.c	2010-10-20 00:16:08.274985517 +0900
@@ -576,7 +576,7 @@
 		struct group *grp;
 		int   rc = 0;
 		gid_t  gid,egid;
-		grp = getgrnam("pkcs11");
+		grp = getgrnam(PKCS11GROUP);
 		if (grp) {
 			// Check for member of group..
 			// SAB get login seems to not work with some
@@ -1064,7 +1064,19 @@
 	//
 	object_mgr_destroy_token_objects();
 #if 0 /* TODO: Implement delete_all_files_in_dir() */
+#if HAVE_ASPRINTF
 	local_rc = asprintf(&pk_full_path, "%s/%s", pk_dir, PK_LITE_OBJ_DIR);
+#else
+	pk_full_path = malloc(1024);
+	if( pk_full_path != NULL ) {
+		local_rc = snprintf(pk_full_path, 1023, "%s/%s",
+				pk_dir, PK_LITE_OBJ_DIR);
+		if( local_rc == -1 ) free(pk_full_path);
+	}
+	else {
+		local_rc = -1;
+	}
+#endif
 	if (local_rc == -1) {
 		rc = CKR_HOST_MEMORY;
 		goto out;
@@ -1075,8 +1087,20 @@
 		goto out;
 	}
 #endif
+#if HAVE_ASPRINTF
 	local_rc = asprintf(&s, "%s %s/%s/* > /dev/null 2>&1", DEL_CMD, pk_dir,
 			    PK_LITE_OBJ_DIR);
+#else
+	s = malloc(1024);
+	if( s != NULL ) {
+		local_rc = snprintf(s, 1023, "%s %s/%s/* > /dev/null 2>&1",
+				DEL_CMD, pk_dir, PK_LITE_OBJ_DIR);
+		if( local_rc == -1 ) free(s);
+	}
+	else {
+		local_rc = -1;
+	}
+#endif
 	if (local_rc == -1) {
 		rc = CKR_HOST_MEMORY;
 		goto out;
