--- smbd/statvfs.c.orig	Wed Nov  9 19:28:55 2005
+++ smbd/statvfs.c	Thu Jan  5 04:26:54 2006
@@ -3,6 +3,7 @@
    VFS API's statvfs abstraction
    Copyright (C) Alexander Bokovoy			2005
    Copyright (C) Steve French				2005
+   Copyright (C) Timur I. Bakeyev			2005
    
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -41,6 +42,27 @@
 	}
 	return result;
 }
+#elif defined(FREEBSD)
+static int bsd_statvfs(const char *path, vfs_statvfs_struct *statbuf)
+{
+	struct statfs statfs_buf;
+	int result;
+
+	result = statfs(path, &statfs_buf);
+
+	if (!result) {
+		statbuf->OptimalTransferSize = statfs_buf.f_iosize;
+		statbuf->BlockSize = statfs_buf.f_bsize;
+		statbuf->TotalBlocks = statfs_buf.f_blocks;
+		statbuf->BlocksAvail = statfs_buf.f_bfree;
+		statbuf->UserBlocksAvail = statfs_buf.f_bavail;
+		statbuf->TotalFileNodes = statfs_buf.f_files;
+		statbuf->FreeFileNodes = statfs_buf.f_ffree;
+		statbuf->FsIdentifier = 
+			(((SMB_BIG_UINT)statfs_buf.f_fsid.val[0]<<32) & 0xffffffff00000000LL) | (SMB_BIG_UINT)statfs_buf.f_fsid.val[1];
+	}
+	return result;
+}
 #endif
 
 /* 
@@ -53,6 +75,8 @@
 {
 #if defined(LINUX)
 	return linux_statvfs(path, statbuf);
+#elif defined(FREEBSD)
+	return bsd_statvfs(path, statbuf);
 #else
 	/* BB change this to return invalid level */
 #ifdef EOPNOTSUPP
