--- source3/modules/vfs_cap.c.orig	2022-01-24 10:26:59 UTC
+++ source3/modules/vfs_cap.c
@@ -112,7 +112,10 @@ static struct dirent *cap_readdir(vfs_handle_struct *h
 		return NULL;
 	}
 	talloc_set_name_const(newdirent, "struct dirent");
-	memcpy(newdirent, result, sizeof(struct dirent));
+	/* See FreeBSD bug #275597 for an explanation of this patch. */
+	/* memcpy(newdirent, result, sizeof(struct dirent)); */
+	memcpy(newdirent, result, result->d_reclen);
+	/*******************************************************************/
 	memcpy(&newdirent->d_name, newname, newnamelen);
 	return newdirent;
 }
