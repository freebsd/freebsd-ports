From 6a95f51f5ea1c60b5c11e8dd7e4a03ca5ef8049f Mon Sep 17 00:00:00 2001
From: Ralph Boehme <slow@samba.org>
Date: Sat, 28 Oct 2017 16:13:16 +0200
Subject: [PATCH] WIP: vfs_zfsacl: fix compilation error

Bug: https://bugzilla.samba.org/show_bug.cgi?id=6133
--- source3/modules/vfs_zfsacl.c.orig	2017-11-02 11:38:36 UTC
+++ source3/modules/vfs_zfsacl.c
@@ -51,6 +51,7 @@ static NTSTATUS zfs_get_nt_acl_common(st
 	SMB_STRUCT_STAT sbuf;
 	const SMB_STRUCT_STAT *psbuf = NULL;
 	int ret;
+	bool is_dir;
 
 	if (VALID_STAT(smb_fname->st)) {
 		psbuf = &smb_fname->st;
@@ -65,10 +66,7 @@ static NTSTATUS zfs_get_nt_acl_common(st
 		}
 		psbuf = &sbuf;
 	}
-
-	if (S_ISDIR(psbuf->st_ex_mode) && (ace->aceMask & SMB_ACE4_ADD_FILE)) {
-		ace->aceMask |= SMB_ACE4_DELETE_CHILD;
-	}
+	is_dir = S_ISDIR(psbuf->st_ex_mode);
 
 	/* read the number of file aces */
 	if((naces = acl(smb_fname->base_name, ACE_GETACLCNT, 0, NULL)) == -1) {
@@ -115,6 +113,10 @@ static NTSTATUS zfs_get_nt_acl_common(st
 			aceprop.aceMask |= SMB_ACE4_SYNCHRONIZE;
 		}
 
+		if (is_dir && (aceprop.aceMask & SMB_ACE4_ADD_FILE)) {
+			aceprop.aceMask |= SMB_ACE4_DELETE_CHILD;
+		}
+
 		if(aceprop.aceFlags & ACE_OWNER) {
 			aceprop.flags = SMB_ACE4_ID_SPECIAL;
 			aceprop.who.special_id = SMB_ACE4_WHO_OWNER;
