--- source3/modules/vfs_full_audit.c.orig	2018-05-15 10:58:37 UTC
+++ source3/modules/vfs_full_audit.c
@@ -613,6 +613,7 @@ static int smb_full_audit_connect(vfs_ha
 			 const char *svc, const char *user)
 {
 	int result;
+	const char *none[] = { "none" };
 	struct vfs_full_audit_private_data *pd = NULL;
 
 	result = SMB_VFS_NEXT_CONNECT(handle, svc, user);
@@ -652,10 +653,10 @@ static int smb_full_audit_connect(vfs_ha
 
 	pd->success_ops = init_bitmap(
 		pd, lp_parm_string_list(SNUM(handle->conn), "full_audit",
-					"success", NULL));
+					"success", none));
 	pd->failure_ops = init_bitmap(
 		pd, lp_parm_string_list(SNUM(handle->conn), "full_audit",
-					"failure", NULL));
+					"failure", none));
 
 	/* Store the private data. */
 	SMB_VFS_HANDLE_SET_DATA(handle, pd, NULL,
