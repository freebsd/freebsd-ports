[FDclone-users:00275]
  Fix a bug where a recursive copy fails when the destination directory
  has a trailing slash.
--- apply.c.orig	Tue Jan  6 10:12:40 2004
+++ apply.c	Sun May 23 05:32:39 2004
@@ -526,7 +526,9 @@
 			break;
 	}
 	if (destdir) free(destdir);
-	destdir = strdup2(&(dest[strlen(destpath) + 1]));
+	destdir = &(dest[strlen(destpath)]);
+	while (*destdir == _SC_) destdir++;
+	destdir = strdup2(destdir);
 	return(0);
 }
 

[FDclone-users:00276]
  Remove superfluous calls of chflags(2) to supress errors on filesystems
  that do not support file flags.
--- apply.c.orig	Tue Jan  6 10:12:40 2004
+++ apply.c	Sun May 23 04:14:55 2004
@@ -902,7 +904,7 @@
 
 	attrmode = (flag & 1) ? attr.mode : 0xffff;
 #ifdef	HAVEFLAGS
-	attrflags = (flag & 1) ? attr.flags : 0xffffffff;
+	attrflags = (flag == 3) ? attr.flags : 0xffffffff;
 #endif
 	attrtime = (flag & 2) ? timelocal2(tm) : (time_t)-1;
 	if (flag == 3) {
