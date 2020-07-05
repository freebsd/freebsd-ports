--- source3/modules/vfs_zfsacl.c.orig	2018-07-12 08:23:36 UTC
+++ source3/modules/vfs_zfsacl.c
@@ -51,6 +51,7 @@ static NTSTATUS zfs_get_nt_acl_common(st
 	SMB_STRUCT_STAT sbuf;
 	const SMB_STRUCT_STAT *psbuf = NULL;
 	int ret;
+	bool inherited_is_present = False;
 	bool is_dir;
 
 	if (VALID_STAT(smb_fname->st)) {
@@ -117,6 +118,11 @@ static NTSTATUS zfs_get_nt_acl_common(st
 			aceprop.aceMask |= SMB_ACE4_DELETE_CHILD;
 		}
 
+#ifdef ACE_INHERITED_ACE
+ 		if(aceprop.aceFlags & ACE_INHERITED_ACE) {
+ 			inherited_is_present = true;
+ 		}
+#endif
 		if(aceprop.aceFlags & ACE_OWNER) {
 			aceprop.flags = SMB_ACE4_ID_SPECIAL;
 			aceprop.who.special_id = SMB_ACE4_WHO_OWNER;
@@ -133,6 +139,13 @@ static NTSTATUS zfs_get_nt_acl_common(st
 			return NT_STATUS_NO_MEMORY;
 	}
 
+#ifdef ACE_INHERITED_ACE
+ 	if (!inherited_is_present
+	    && lp_parm_bool(conn->params->service, "zfsacl", "map_dacl_protected", False)){
+		DBG_DEBUG("setting dacl_protected flag on %s\n", smb_fname->base_name);
+		smbacl4_set_controlflags(pacl, SEC_DESC_DACL_PROTECTED|SEC_DESC_SELF_RELATIVE);
+	}
+#endif
 	*ppacl = pacl;
 	return NT_STATUS_OK;
 }
