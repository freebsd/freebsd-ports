From d9b748869a8f4018ebee302aae8246bf29f60309 Mon Sep 17 00:00:00 2001
From: "Timur I. Bakeyev" <timur@iXsystems.com>
Date: Fri, 1 Jun 2018 01:35:08 +0800
Subject: [PATCH] vfs_fruit: allow broken AFP_Signature where the first
 byte is 0

FreeBSD bug ... caused the first byte of the AFP_AfpInfo xattr to be 0
instead of 'A'. This hack allows such broken AFP_AfpInfo blobs to be
parsed by afpinfo_unpack().

FreeBSD Bug: https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=228462

Signed-off-by: Ralph Boehme <slow@samba.org>

--- source3/lib/adouble.c.orig	2020-05-08 09:30:43 UTC
+++ source3/lib/adouble.c
@@ -2662,6 +2662,8 @@ ssize_t afpinfo_pack(const AfpInfo *ai, char *buf)
 	return AFP_INFO_SIZE;
 }
 
+#define BROKEN_FREEBSD_AFP_Signature 0x00465000
+
 /**
  * Unpack a buffer into a AfpInfo structure
  *
@@ -2679,12 +2681,22 @@ AfpInfo *afpinfo_unpack(TALLOC_CTX *ctx, const void *d
 	ai->afpi_Version = RIVAL(data, 4);
 	ai->afpi_BackupTime = RIVAL(data, 12);
 	memcpy(ai->afpi_FinderInfo, (const char *)data + 16,
-	       sizeof(ai->afpi_FinderInfo));
+		sizeof(ai->afpi_FinderInfo));
 
-	if (ai->afpi_Signature != AFP_Signature
-	    || ai->afpi_Version != AFP_Version) {
-		DEBUG(1, ("Bad AfpInfo signature or version\n"));
+	if (ai->afpi_Signature != AFP_Signature) {
+		DBG_WARNING("Bad AFP signature [%x]\n", ai->afpi_Signature);
+
+		if (ai->afpi_Signature != BROKEN_FREEBSD_AFP_Signature) {
+			DBG_ERR("Bad AfpInfo signature\n");
+			TALLOC_FREE(ai);
+			return NULL;
+		}
+	}
+
+	if (ai->afpi_Version != AFP_Version) {
+		DBG_ERR("Bad AfpInfo version\n");
 		TALLOC_FREE(ai);
+		return NULL;
 	}
 
 	return ai;
--- source3/modules/vfs_fruit.c.orig	2021-01-26 08:16:58 UTC
+++ source3/modules/vfs_fruit.c
@@ -2146,13 +2146,30 @@ static ssize_t fruit_pread_meta_stream(vfs_handle_stru
 	struct fio *fio = (struct fio *)VFS_FETCH_FSP_EXTENSION(handle, fsp);
 	ssize_t nread;
 	int ret;
+	char *p = (char *)data;
 
 	if (fio->fake_fd) {
 		return -1;
 	}
 
 	nread = SMB_VFS_NEXT_PREAD(handle, fsp, data, n, offset);
-	if (nread == -1 || nread == n) {
+	if (nread <= 0) {
+		/*
+		 * fruit_meta_open_stream() removes O_CREAT flag
+		 * from xattr open. This results in vfs_streams_xattr
+		 * not generating an FSP extension for the files_struct
+		 * and causes subsequent pread() of stream to return
+		 * nread=0 if pread() occurs before pwrite().
+		 */
+		return nread;
+	}
+
+	if (nread == n) {
+		if (offset == 0 && nread > 3 && p[0] == 0 && p[1] == 'F' && p[2] == 'P') {
+			DBG_NOTICE("Fixing AFP_Info of [%s]\n",
+				    fsp_str_dbg(fsp));
+			p[0] = 'A';
+		}
 		return nread;
 	}
 
