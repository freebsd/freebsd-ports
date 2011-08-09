--- ./source3/modules/vfs_zfsacl.c.orig	2011-07-24 22:04:44.000000000 +0200
+++ ./source3/modules/vfs_zfsacl.c	2011-07-29 19:11:57.000000000 +0200
@@ -251,8 +251,7 @@
 	return (SMB_ACL_T)NULL;
 }
 SMB_ACL_T zfsacl_fail__sys_acl_get_fd(vfs_handle_struct *handle,
-				      files_struct *fsp,
-				      int fd)
+				      files_struct *fsp)
 {
 	return (SMB_ACL_T)NULL;
 }
@@ -267,7 +266,7 @@
 
 int zfsacl_fail__sys_acl_set_fd(vfs_handle_struct *handle,
 				files_struct *fsp,
-				int fd, SMB_ACL_T theacl)
+				SMB_ACL_T theacl)
 {
 	return -1;
 }
