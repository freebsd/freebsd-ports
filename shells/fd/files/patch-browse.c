[FDclone-users:00310]

--- browse.c~	2004-07-07 00:00:00.000000000 +0900
+++ browse.c	2004-07-15 18:50:00.096771592 +0900
@@ -684,7 +684,7 @@
 # ifndef	_NOARCHIVE
 	else if (archivefile) {
 		if (namep -> linkname)
-			strncpy3(buf, &(namep -> linkname[len]), &w, 0);
+			strncpy3(buf, namep -> linkname, &w, len);
 	}
 # endif
 	else {
@@ -693,7 +693,7 @@
 			tmp, width * 2 + len);
 		if (i >= 0) {
 			tmp[i] = '\0';
-			strncpy3(buf, &(tmp[len]), &w, 0);
+			strncpy3(buf, tmp, &w, len);
 		}
 		free(tmp);
 	}

[FDclone-users:00311]

diff -u ../old/FD-2.05g/browse.c ./browse.c
--- ../old/FD-2.05g/browse.c	Wed Jul  7 00:00:00 2004
+++ ./browse.c	Sat Jul 17 02:56:26 2004
@@ -707,7 +707,7 @@
 	struct tm *tm;
 	int len;
 
-	if (!filelist || maxfile < 0) return;
+	if (!filelist || filepos < 0 || maxfile < 0) return;
 
 #ifndef	_NOTRADLAYOUT
 	if (istradlayout()) {
@@ -1216,7 +1216,7 @@
 VOID rewritefile(all)
 int all;
 {
-	if (!filelist || maxfile < 0) return;
+	if (!filelist || filepos < 0 || maxfile < 0) return;
 	if (all > 0) {
 		title();
 		helpbar();
@@ -1439,9 +1439,9 @@
 		re = regexp_init(findpattern, -1);
 	}
 
+	maxfile = 0;
 #ifndef	_NOARCHIVE
 	if (archivefile) {
-		maxfile = (*archivedir) ? 1 : 0;
 		blocksize = (off_t)1;
 		if (sorttype < 100) sorton = 0;
 		copyarcf(re, arcre);
@@ -1449,7 +1449,6 @@
 	else
 #endif
 	{
-		maxfile = 0;
 		blocksize = getblocksize(".");
 		if (sorttype < 100) sorton = sorttype;
 		if (readfilelist(re, arcre)) {
@@ -1657,8 +1656,9 @@
 		else if (no > 4) {
 			char *tmp;
 
-			tmp = (filepos < 0) ? ".." : filelist[filepos].name;
+			tmp = (filepos >= 0) ? filelist[filepos].name : NULL;
 			if (!(cp = archchdir(tmp))) {
+				if (!tmp) tmp = "..";
 				warning(-1, tmp);
 				strcpy(file, tmp);
 			}
