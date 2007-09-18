--- /dev/null	Thu Aug 30 22:11:01 2007
+++ modules/vfs_zfsacl.c	Thu Aug 30 16:33:06 2007
@@ -0,0 +1,187 @@
+/*
+ * Convert ZFS/NFSv4 acls to NT acls and vice versa.
+ *
+ * Copyright (C) Jiri Sasek, 2007
+ * based on the foobar.c module which is copyrighted by Volker Lendecke
+ *
+ * This program is free software; you can redistribute it and/or modify
+ * it under the terms of the GNU General Public License as published by
+ * the Free Software Foundation; either version 2 of the License, or
+ * (at your option) any later version.
+ *
+ * This program is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ * GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with this program; if not, write to the Free Software
+ * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+ *
+ */
+
+#include "includes.h"
+#include "nfs4_acls.h"
+
+#undef DBGC_CLASS
+#define DBGC_CLASS DBGC_VFS
+
+#define ZFSACL_MODULE_NAME "zfsacl"
+
+/* zfs_get_nt_acl()
+ * read the local file's acls and return it in NT form
+ * using the NFSv4 format conversion
+ */
+static size_t zfs_get_nt_acl(struct files_struct *fsp, uint32 security_info,
+			     struct security_descriptor **ppdesc)
+{
+	int naces, i;
+	ace_t *acebuf;
+	SMB4ACL_T *pacl;
+	TALLOC_CTX	*mem_ctx;
+
+	/* read the number of file aces */
+	if((naces = acl(fsp->fsp_name, ACE_GETACLCNT, 0, NULL)) == -1) {
+		if(errno == ENOSYS) {
+			DEBUG(9, ("acl(ACE_GETACLCNT, %s): Operation is not supported on the filesystem where the file reside"));
+		} else {
+			DEBUG(9, ("acl(ACE_GETACLCNT, %s): %s ", fsp->fsp_name,
+					strerror(errno)));
+		}
+		return 0;
+	}
+	/* allocate the field of ZFS aces */
+	mem_ctx = main_loop_talloc_get();
+	acebuf = (ace_t *) talloc_size(mem_ctx, sizeof(ace_t)*naces);
+	if(acebuf == NULL) {
+		errno = ENOMEM;
+		return 0;
+	}
+	/* read the aces into the field */
+	if(acl(fsp->fsp_name, ACE_GETACL, naces, acebuf) < 0) {
+		DEBUG(9, ("acl(ACE_GETACL, %s): %s ", fsp->fsp_name,
+				strerror(errno)));
+		return 0;
+	}
+	/* create SMB4ACL data */
+	if((pacl = smb_create_smb4acl()) == NULL) return 0;
+	for(i=0; i<naces; i++) {
+		SMB_ACE4PROP_T aceprop;
+
+		aceprop.aceType  = (uint32) acebuf[i].a_type;
+		aceprop.aceFlags = (uint32) acebuf[i].a_flags;
+		aceprop.aceMask  = (uint32) acebuf[i].a_access_mask;
+		aceprop.who.id   = (uint32) acebuf[i].a_who;
+		aceprop.flags    = 0;
+		if(smb_add_ace4(pacl, &aceprop) == NULL) return 0;
+	}
+
+	return smb_get_nt_acl_nfs4(fsp, security_info, ppdesc, pacl);
+}
+
+/* call-back function processing the NT acl -> ZFS acl using NFSv4 conv. */
+static BOOL zfs_process_smbacl(files_struct *fsp, SMB4ACL_T *smbacl)
+{
+	int naces = smb_get_naces(smbacl), i;
+	ace_t *acebuf;
+	SMB4ACE_T *smbace;
+	TALLOC_CTX	*mem_ctx;
+
+	/* allocate the field of ZFS aces */
+	mem_ctx = main_loop_talloc_get();
+	acebuf = (ace_t *) talloc_size(mem_ctx, sizeof(ace_t)*naces);
+	if(acebuf == NULL) {
+		errno = ENOMEM;
+		return False;
+	}
+	/* handle all aces */
+	for(smbace = smb_first_ace4(smbacl), i = 0;
+			smbace!=NULL;
+			smbace = smb_next_ace4(smbace), i++) {
+		SMB_ACE4PROP_T *aceprop = smb_get_ace4(smbace);
+
+		acebuf[i].a_type        = aceprop->aceType;
+		acebuf[i].a_flags       = aceprop->aceFlags;
+		acebuf[i].a_access_mask = aceprop->aceMask;
+		acebuf[i].a_who         = aceprop->who.id;
+	}
+	SMB_ASSERT(i == naces);
+
+	/* store acl */
+	if(acl(fsp->fsp_name, ACE_SETACL, naces, acebuf)) {
+		if(errno == ENOSYS) {
+			DEBUG(9, ("acl(ACE_SETACL, %s): Operation is not supported on the filesystem where the file reside"));
+		} else {
+			DEBUG(9, ("acl(ACE_SETACL, %s): %s ", fsp->fsp_name,
+					strerror(errno)));
+		}
+		return 0;
+	}
+
+	return True;
+}
+
+/* zfs_set_nt_acl()
+ * set the local file's acls obtaining it in NT form
+ * using the NFSv4 format conversion
+ */
+static NTSTATUS zfs_set_nt_acl(vfs_handle_struct *handle, files_struct *fsp,
+			   uint32 security_info_sent,
+			   struct security_descriptor *psd)
+{
+	return smb_set_nt_acl_nfs4(fsp, security_info_sent, psd,
+			zfs_process_smbacl);
+}
+
+static size_t zfsacl_fget_nt_acl(struct vfs_handle_struct *handle,
+				 struct files_struct *fsp,
+				 int fd,  uint32 security_info,
+				 struct security_descriptor **ppdesc)
+{
+	return zfs_get_nt_acl(fsp, security_info, ppdesc);
+}
+
+static size_t zfsacl_get_nt_acl(struct vfs_handle_struct *handle,
+				struct files_struct *fsp,
+				const char *name,  uint32 security_info,
+				struct security_descriptor **ppdesc)
+{
+	return zfs_get_nt_acl(fsp, security_info, ppdesc);
+}
+
+static NTSTATUS zfsacl_fset_nt_acl(vfs_handle_struct *handle,
+			 files_struct *fsp,
+			 int fd, uint32 security_info_sent,
+			 SEC_DESC *psd)
+{
+	return zfs_set_nt_acl(handle, fsp, security_info_sent, psd);
+}
+
+static NTSTATUS zfsacl_set_nt_acl(vfs_handle_struct *handle,
+		       files_struct *fsp,
+		       const char *name, uint32 security_info_sent,
+		       SEC_DESC *psd)
+{
+	return zfs_set_nt_acl(handle, fsp, security_info_sent, psd);
+}
+
+/* VFS operations structure */
+
+static vfs_op_tuple zfsacl_ops[] = {	
+	{SMB_VFS_OP(zfsacl_fget_nt_acl), SMB_VFS_OP_FGET_NT_ACL,
+	 SMB_VFS_LAYER_OPAQUE},
+	{SMB_VFS_OP(zfsacl_get_nt_acl), SMB_VFS_OP_GET_NT_ACL,
+	 SMB_VFS_LAYER_OPAQUE},
+	{SMB_VFS_OP(zfsacl_fset_nt_acl), SMB_VFS_OP_FSET_NT_ACL,
+	 SMB_VFS_LAYER_OPAQUE},
+	{SMB_VFS_OP(zfsacl_set_nt_acl), SMB_VFS_OP_SET_NT_ACL,
+	 SMB_VFS_LAYER_OPAQUE},
+	{SMB_VFS_OP(NULL), SMB_VFS_OP_NOOP, SMB_VFS_LAYER_NOOP}
+};
+
+NTSTATUS vfs_zfsacl_init(void);
+NTSTATUS vfs_zfsacl_init(void)
+{
+	return smb_register_vfs(SMB_VFS_INTERFACE_VERSION, "zfsacl",
+				zfsacl_ops);
+}
