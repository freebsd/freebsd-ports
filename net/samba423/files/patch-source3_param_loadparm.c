--- source3/param/loadparm.c.orig	2025-02-06 10:31:54 UTC
+++ source3/param/loadparm.c
@@ -2890,9 +2890,29 @@ static void init_locals(void)
 		} else {
 			if (lp_parm_const_string(-1, "xattr_tdb", "file", NULL)) {
 				lp_do_parameter(-1, "vfs objects", "dfs_samba4 acl_xattr xattr_tdb");
+			/*
+			 * By default, the samba sysvol is located in the statedir. Provisioning will fail in setntacl
+			 * unless we have zfacl enabled. Unfortunately, at this point the smb.conf has not been generated.
+			 * This workaround is freebsd-specific.
+			 */
+#if defined(_PC_ACL_EXTENDED)
+			} else if (pathconf(lp_state_directory(), _PC_ACL_EXTENDED) == 1) {
+				lp_do_parameter(-1, "vfs objects", "dfs_samba4 freebsd");
+#endif
+#if defined(_PC_ACL_NFS4)
+			} else if (pathconf(lp_state_directory(), _PC_ACL_NFS4) == 1) {
+				lp_do_parameter(-1, "vfs objects", "dfs_samba4 zfsacl");
+#endif
 			} else if (lp_parm_const_string(-1, "posix", "eadb", NULL)) {
 				lp_do_parameter(-1, "vfs objects", "dfs_samba4 acl_xattr posix_eadb");
 			} else {
+				/*
+				 * This should only set dfs_samba4 and leave acl_xattr
+				 * to be set later (or zfsacl). The only reason the decision
+				 * can't be made here to load acl_xattr or zfsacl is
+				 * that we don't have access to what the target
+				 * directory is.
+				 */
 				lp_do_parameter(-1, "vfs objects", "dfs_samba4 acl_xattr");
 			}
 		}
