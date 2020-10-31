--- source3/torture/cmd_vfs.c.orig	2019-01-15 10:07:00 UTC
+++ source3/torture/cmd_vfs.c
@@ -145,7 +145,84 @@ static NTSTATUS cmd_disk_free(struct vfs_state *vfs, T
 	return NT_STATUS_OK;
 }
 
+static NTSTATUS cmd_get_quota(struct vfs_state *vfs, TALLOC_CTX *mem_ctx, int argc, const char **argv)
+{
+	struct smb_filename *smb_fname = NULL;
+	uint64_t quota, bsize, dfree, dsize;
+	enum SMB_QUOTA_TYPE qtype;
+	SMB_DISK_QUOTA D;
+	unid_t id;
+	int r;
 
+	if (argc != 4) {
+		printf("Usage: get_quota <path> [user|group] id\n");
+		return NT_STATUS_OK;
+	}
+
+	smb_fname = synthetic_smb_fname(talloc_tos(),
+					argv[1],
+					NULL,
+					NULL,
+					0,
+					ssf_flags());
+	if (smb_fname == NULL) {
+		return NT_STATUS_NO_MEMORY;
+	}
+
+	if(strcmp(argv[2], "user") == 0) {
+		qtype = SMB_USER_FS_QUOTA_TYPE;
+	}
+	else if(strcmp(argv[2], "group") == 0) {
+		qtype = SMB_GROUP_FS_QUOTA_TYPE;
+	}
+	else {
+		printf("Usage: get_quota <path> [user|group] id\n");
+		return NT_STATUS_OK;
+	}
+
+	id.uid = atoi(argv[3]);
+
+	ZERO_STRUCT(D);
+
+	r = SMB_VFS_GET_QUOTA(vfs->conn, smb_fname, qtype, id, &D);
+
+	if (r == -1 && errno != ENOSYS) {
+		return NT_STATUS_UNSUCCESSFUL;
+	}
+
+	if (r == 0 && (D.qflags & QUOTAS_DENY_DISK) == 0) {
+		return NT_STATUS_UNSUCCESSFUL;
+	}
+
+	bsize = D.bsize;
+	/* Use softlimit to determine disk space, except when it has been exceeded */
+	if (
+		(D.softlimit && D.curblocks >= D.softlimit) ||
+		(D.hardlimit && D.curblocks >= D.hardlimit) ||
+		(D.isoftlimit && D.curinodes >= D.isoftlimit) ||
+		(D.ihardlimit && D.curinodes>=D.ihardlimit)
+	) {
+		dfree = 0;
+		dsize = D.curblocks;
+	} else if (D.softlimit==0 && D.hardlimit==0) {
+		return NT_STATUS_UNSUCCESSFUL;
+	} else {
+		if (D.softlimit == 0) {
+			D.softlimit = D.hardlimit;
+		}
+		dfree = D.softlimit - D.curblocks;
+		dsize = D.softlimit;
+	}
+
+	printf("get_quota: bsize = %lu, dfree = %lu, dsize = %lu\n",
+			(unsigned long)bsize,
+			(unsigned long)dfree,
+			(unsigned long)dsize);
+
+	return NT_STATUS_OK;
+}
+
+
 static NTSTATUS cmd_opendir(struct vfs_state *vfs, TALLOC_CTX *mem_ctx, int argc, const char **argv)
 {
 	struct smb_filename *smb_fname = NULL;
@@ -2028,6 +2105,7 @@ struct cmd_set vfs_commands[] = {
 	{ "connect",   cmd_connect,   "VFS connect()",    "connect" },
 	{ "disconnect",   cmd_disconnect,   "VFS disconnect()",    "disconnect" },
 	{ "disk_free",   cmd_disk_free,   "VFS disk_free()",    "disk_free <path>" },
+	{ "get_quota",   cmd_get_quota,   "VFS get_quota()",    "get_quota <path> [user|group] id" },
 	{ "opendir",   cmd_opendir,   "VFS opendir()",    "opendir <fname>" },
 	{ "readdir",   cmd_readdir,   "VFS readdir()",    "readdir" },
 	{ "mkdir",   cmd_mkdir,   "VFS mkdir()",    "mkdir <path>" },
@@ -2057,33 +2135,22 @@ struct cmd_set vfs_commands[] = {
 	{ "link",   cmd_link,   "VFS link()",    "link <oldpath> <newpath>" },
 	{ "mknod",   cmd_mknod,   "VFS mknod()",    "mknod <path> <mode> <dev>" },
 	{ "realpath",   cmd_realpath,   "VFS realpath()",    "realpath <path>" },
-	{ "getxattr", cmd_getxattr, "VFS getxattr()",
-	  "getxattr <path> <name>" },
-	{ "listxattr", cmd_listxattr, "VFS listxattr()",
-	  "listxattr <path>" },
-	{ "setxattr", cmd_setxattr, "VFS setxattr()",
-	  "setxattr <path> <name> <value> [<flags>]" },
-	{ "removexattr", cmd_removexattr, "VFS removexattr()",
-	  "removexattr <path> <name>\n" },
-	{ "fget_nt_acl", cmd_fget_nt_acl, "VFS fget_nt_acl()", 
-	  "fget_nt_acl <fd>\n" },
-	{ "get_nt_acl", cmd_get_nt_acl, "VFS get_nt_acl()", 
-	  "get_nt_acl <path>\n" },
-	{ "fset_nt_acl", cmd_fset_nt_acl, "VFS fset_nt_acl()", 
-	  "fset_nt_acl <fd>\n" },
-	{ "set_nt_acl", cmd_set_nt_acl, "VFS open() and fset_nt_acl()", 
-	  "set_nt_acl <file>\n" },
+	{ "getxattr", cmd_getxattr, "VFS getxattr()", "getxattr <path> <name>" },
+	{ "listxattr", cmd_listxattr, "VFS listxattr()", "listxattr <path>" },
+	{ "setxattr", cmd_setxattr, "VFS setxattr()", "setxattr <path> <name> <value> [<flags>]" },
+	{ "removexattr", cmd_removexattr, "VFS removexattr()", "removexattr <path> <name>\n" },
+	{ "fget_nt_acl", cmd_fget_nt_acl, "VFS fget_nt_acl()", "fget_nt_acl <fd>\n" },
+	{ "get_nt_acl", cmd_get_nt_acl, "VFS get_nt_acl()", "get_nt_acl <path>\n" },
+	{ "fset_nt_acl", cmd_fset_nt_acl, "VFS fset_nt_acl()", "fset_nt_acl <fd>\n" },
+	{ "set_nt_acl", cmd_set_nt_acl, "VFS open() and fset_nt_acl()", "set_nt_acl <file>\n" },
 	{ "sys_acl_get_file", cmd_sys_acl_get_file, "VFS sys_acl_get_file()", "sys_acl_get_file <path>" },
 	{ "sys_acl_get_fd", cmd_sys_acl_get_fd, "VFS sys_acl_get_fd()", "sys_acl_get_fd <fd>" },
-	{ "sys_acl_blob_get_file", cmd_sys_acl_blob_get_file,
-	  "VFS sys_acl_blob_get_file()", "sys_acl_blob_get_file <path>" },
-	{ "sys_acl_blob_get_fd", cmd_sys_acl_blob_get_fd,
-	  "VFS sys_acl_blob_get_fd()", "sys_acl_blob_get_fd <path>" },
+	{ "sys_acl_blob_get_file", cmd_sys_acl_blob_get_file, "VFS sys_acl_blob_get_file()", "sys_acl_blob_get_file <path>" },
+	{ "sys_acl_blob_get_fd", cmd_sys_acl_blob_get_fd, "VFS sys_acl_blob_get_fd()", "sys_acl_blob_get_fd <path>" },
 	{ "sys_acl_delete_def_file", cmd_sys_acl_delete_def_file, "VFS sys_acl_delete_def_file()", "sys_acl_delete_def_file <path>" },
 
 
-	{ "test_chain", cmd_test_chain, "test chain code",
-	  "test_chain" },
+	{ "test_chain", cmd_test_chain, "test chain code", "test_chain" },
 	{ "translate_name", cmd_translate_name, "VFS translate_name()", "translate_name unix_filename" },
 	{0}
 };
