A patch taken from: [FDclone-users:00027]

diff -ur ../old/FD-2.01b/archive.c ./archive.c
--- ../old/FD-2.01b/archive.c	Wed Jul 10 00:00:00 2002
+++ ./archive.c	Mon Aug 19 08:11:18 2002
@@ -1188,7 +1188,7 @@
 		if (*path == _SC_) len = 1;
 		else if ((cp = strdelim(path, 0))) len = cp - path;
 		else len = strlen(path);
-		if (strncmp(path, "..", len)) {
+		if (len != 2 || strncmp(path, "..", len)) {
 			if (!searcharcdir(path, len)) {
 				strcpy(archivedir, duparcdir);
 				return(NULL);
