--- src/sys/kern/vfs_init.c.orig	2020-08-29 05:04:12 UTC
+++ src/sys/kern/vfs_init.c
@@ -366,7 +366,7 @@ mount_listener_cb(kauth_cred_t cred, kauth_action_t ac
 	enum kauth_system_req req;
 
 	result = KAUTH_RESULT_DEFER;
-	req = (enum kauth_system_req)arg0;
+	req = (enum kauth_system_req)(uintptr_t)arg0;
 
 	if (action != KAUTH_SYSTEM_MOUNT)
 		return result;
