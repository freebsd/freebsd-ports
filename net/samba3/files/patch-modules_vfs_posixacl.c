--- modules/vfs_posixacl.c.orig	Wed Apr 18 11:51:22 2007
+++ modules/vfs_posixacl.c	Wed Apr 18 11:51:48 2007
@@ -200,9 +200,9 @@
 		return False;
 	}
 	ace->a_perm = 0;
-	ace->a_perm |= (acl_get_perm(permset, ACL_READ) ? SMB_ACL_READ : 0);
-	ace->a_perm |= (acl_get_perm(permset, ACL_WRITE) ? SMB_ACL_WRITE : 0);
-	ace->a_perm |= (acl_get_perm(permset, ACL_EXECUTE) ? SMB_ACL_EXECUTE : 0);
+	ace->a_perm |= (acl_get_perm_np(permset, ACL_READ) ? SMB_ACL_READ : 0);
+	ace->a_perm |= (acl_get_perm_np(permset, ACL_WRITE) ? SMB_ACL_WRITE : 0);
+	ace->a_perm |= (acl_get_perm_np(permset, ACL_EXECUTE) ? SMB_ACL_EXECUTE : 0);
 	return True;
 }
 
