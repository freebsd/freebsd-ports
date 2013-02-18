--- ./source3/modules/vfs_zfsacl.c.orig	2013-02-05 12:25:25.000000000 +0000
+++ ./source3/modules/vfs_zfsacl.c	2013-02-06 02:16:53.149872040 +0000
@@ -269,13 +269,14 @@
 
 static SMB_ACL_T zfsacl_fail__sys_acl_get_file(vfs_handle_struct *handle,
 					       const char *path_p,
-					       SMB_ACL_TYPE_T type)
+					       SMB_ACL_TYPE_T type,
+					       TALLOC_CTX *mem_ctx)
 {
 	return (SMB_ACL_T)NULL;
 }
 
 static SMB_ACL_T zfsacl_fail__sys_acl_get_fd(vfs_handle_struct *handle,
-					     files_struct *fsp)
+					     files_struct *fsp, TALLOC_CTX *mem_ctx)
 {
 	return (SMB_ACL_T)NULL;
 }
