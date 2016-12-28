--- source3/smbd/close.c.orig	2016-12-25 13:09:22.100676000 +0000
+++ source3/smbd/close.c	2016-12-25 13:09:59.877256000 +0000
@@ -168,7 +168,7 @@
 	unsigned int num_streams = 0;
 	TALLOC_CTX *frame = talloc_stackframe();
 	NTSTATUS status;
-	bool saved_posix_pathnames;
+	bool saved_posix_pathnames = false;
 
 	status = vfs_streaminfo(conn, NULL, fname, talloc_tos(),
 				&num_streams, &stream_info);
