--- syscall.c.orig	2013-01-10 18:53:44.000000000 -0700
+++ syscall.c	2013-01-10 18:53:56.000000000 -0700
@@ -114,8 +114,16 @@
 #ifdef SUPPORT_FORCE_CHANGE
 	if (force_change && (errno == EPERM || errno == EACCES)) {
 		char parent[MAXPATHLEN];
+		int parent_flags;
 		int saved_errno = errno;
-		int parent_flags = make_parentdir_mutable(fname2, force_change, parent, sizeof parent);
+		int file_flags = make_mutable(fname1, NULL, NO_FFLAGS, force_change);
+		if (file_flags) {
+		       	int ret = link(fname1, fname2);
+			undo_make_mutable(fname1, file_flags);
+			if (ret == 0)
+				return 0;
+		}
+		parent_flags = make_parentdir_mutable(fname2, force_change, parent, sizeof parent);
 		if (parent_flags) {
 			int ret = link(fname1, fname2);
 			undo_make_mutable(parent, parent_flags);
