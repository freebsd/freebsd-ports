##
## See https://bugzilla.samba.org/bug/2501 for details
##
diff -urBb --exclude-from=samba-cvs/diff.excludes samba-3.0.12-orig/source/smbd/dir.c samba-3.0.12/source/smbd/dir.c
--- smbd/dir.c.orig	2005-03-18 08:56:41.000000000 -0600
+++ smbd/dir.c	2005-03-21 12:51:56.541216536 -0600
@@ -595,6 +595,13 @@
 BOOL dptr_SearchDir(struct dptr_struct *dptr, const char *name, long *poffset, SMB_STRUCT_STAT *pst)
 {
 	ZERO_STRUCTP(pst);
+
+	if (!dptr->has_wild && (dptr->dir_hnd->offset == -1)) {
+		/* This is a singleton directory and we're already at the end. */
+		*poffset = -1;
+		return False;
+	}
+
 	while (SearchDir(dptr->dir_hnd, name, poffset) == True) {
 		if (is_visible_file(dptr->conn, dptr->path, name, pst, True)) {
 			return True;
