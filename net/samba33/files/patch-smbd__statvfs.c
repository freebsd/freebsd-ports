--- ./smbd/statvfs.c.orig	2009-06-23 09:35:13.000000000 +0000
+++ ./smbd/statvfs.c	2009-06-26 00:41:37.000000000 +0000
@@ -3,6 +3,7 @@
    VFS API's statvfs abstraction
    Copyright (C) Alexander Bokovoy			2005
    Copyright (C) Steve French				2005
+   Copyright (C) Timur I. Bakeyev			2005
    Copyright (C) James Peach				2006
    
    This program is free software; you can redistribute it and/or modify
@@ -47,9 +48,42 @@
 	}
 	return result;
 }
-#endif
+#elif defined(FREEBSD)
+static int bsd_statvfs(const char *path, vfs_statvfs_struct *statbuf)
+{
+	struct statfs statfs_buf;
+	int result;
 
-#if defined(DARWINOS)
+	result = statfs(path, &statfs_buf);
+	if(result != 0) {
+		return result;
+	}
+	
+	statbuf->OptimalTransferSize = statfs_buf.f_iosize;
+	statbuf->BlockSize = statfs_buf.f_bsize;
+	statbuf->TotalBlocks = statfs_buf.f_blocks;
+	statbuf->BlocksAvail = statfs_buf.f_bfree;
+	statbuf->UserBlocksAvail = statfs_buf.f_bavail;
+	statbuf->TotalFileNodes = statfs_buf.f_files;
+	statbuf->FreeFileNodes = statfs_buf.f_ffree;
+	statbuf->FsIdentifier = 
+		(((SMB_BIG_UINT)statfs_buf.f_fsid.val[0]<<32) & 0xffffffff00000000LL) | (SMB_BIG_UINT)statfs_buf.f_fsid.val[1];
+	/* Try to extrapolate some of the fs flags into the
+	 * capabilities
+	 */
+	statbuf->FsCapabilities =
+	    FILE_CASE_SENSITIVE_SEARCH | FILE_CASE_PRESERVED_NAMES;
+	if(statfs_buf.f_flags & MNT_ACLS)
+		statbuf->FsCapabilities |= FILE_PERSISTENT_ACLS;
+	if(statfs_buf.f_flags & MNT_QUOTA)
+		statbuf->FsCapabilities |= FILE_VOLUME_QUOTAS;
+	if(statfs_buf.f_flags & MNT_RDONLY)
+		statbuf->FsCapabilities |= FILE_READ_ONLY_VOLUME;
+
+	return 0;
+}
+
+#elif defined(DARWINOS)
 
 #include <sys/attr.h>
 
@@ -135,6 +169,8 @@
 {
 #if defined(LINUX) && defined(HAVE_FSID_INT)
 	return linux_statvfs(path, statbuf);
+#elif defined(FREEBSD)
+	return bsd_statvfs(path, statbuf);
 #elif defined(DARWINOS)
 	return darwin_statvfs(path, statbuf);
 #else
