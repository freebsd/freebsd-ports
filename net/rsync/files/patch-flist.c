#
# fix --delete SEGV
#  <http://lists.samba.org/archive/rsync/2004-May/009380.html>
#
--- flist.c	29 Apr 2004 19:37:15 -0000	1.218
+++ flist.c	3 May 2004 01:24:10 -0000	1.220
@@ -539,6 +539,7 @@ void receive_file_entry(struct file_stru
 		rdev_major = 0;
 		uid = 0, gid = 0;
 		*lastname = '\0';
+		lastdir_len = -1;
 		return;
 	}
 
@@ -745,7 +746,7 @@ struct file_struct *make_file(char *fnam
 	char *basename, *dirname, *bp;
 	unsigned short flags = 0;
 
-	if (!flist)	/* lastdir isn't valid if flist is NULL */
+	if (!flist || !flist->count)	/* Ignore lastdir when invalid. */
 		lastdir_len = -1;
 
 	if (strlcpy(thisname, fname, sizeof thisname)
