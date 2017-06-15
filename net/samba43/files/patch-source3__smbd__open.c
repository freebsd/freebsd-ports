--- source3/smbd/open.c.orig	2016-12-25 13:08:58.349614000 +0000
+++ source3/smbd/open.c	2016-12-25 13:09:10.968754000 +0000
@@ -3890,7 +3890,7 @@
 	unsigned int num_streams = 0;
 	TALLOC_CTX *frame = talloc_stackframe();
 	NTSTATUS status;
-	bool saved_posix_pathnames;
+	bool saved_posix_pathnames = false;
 
 	status = vfs_streaminfo(conn, NULL, fname, talloc_tos(),
 				&num_streams, &stream_info);
