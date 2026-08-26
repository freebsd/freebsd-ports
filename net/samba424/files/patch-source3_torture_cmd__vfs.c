--- source3/torture/cmd_vfs.c.orig	2026-01-20 15:42:54 UTC
+++ source3/torture/cmd_vfs.c
@@ -146,7 +146,84 @@ static NTSTATUS cmd_disk_free(struct vfs_state *vfs, T
 	return NT_STATUS_OK;
 }
 
+static NTSTATUS cmd_get_quota(struct vfs_state *vfs, TALLOC_CTX *mem_ctx, int argc, const char **argv)
+{
+	struct smb_filename *smb_fname = NULL;
+	uint64_t bsize, dfree, dsize;
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
@@ -2252,6 +2329,7 @@ struct cmd_set vfs_commands[] = {
 	{ "connect",   cmd_connect,   "VFS connect()",    "connect" },
 	{ "disconnect",   cmd_disconnect,   "VFS disconnect()",    "disconnect" },
 	{ "disk_free",   cmd_disk_free,   "VFS disk_free()",    "disk_free <path>" },
+	{ "get_quota",   cmd_get_quota,   "VFS get_quota()",    "get_quota <path> [user|group] id" },
 	{ "opendir",   cmd_opendir,   "VFS opendir()",    "opendir <fname>" },
 	{ "readdir",   cmd_readdir,   "VFS readdir()",    "readdir" },
 	{ "mkdir",   cmd_mkdir,   "VFS mkdir()",    "mkdir <path>" },
