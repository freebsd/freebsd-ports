[FDclone-users:00311]

diff -u ../old/FD-2.05g/archive.c ./archive.c
--- ../old/FD-2.05g/archive.c	Wed Jul  7 00:00:00 2004
+++ ./archive.c	Sat Jul 17 04:59:55 2004
@@ -188,6 +188,7 @@
 static VOID NEAR unpackerror __P_((VOID_A));
 static int NEAR readarchive __P_((char *, launchtable *, int));
 static char *NEAR searcharcdir __P_((char *, int));
+static char *NEAR archoutdir __P_((VOID_A));
 static int NEAR undertmp __P_((char *));
 #ifdef	_NODOSDRIVE
 static char *NEAR genfullpath __P_((char *, char *, char *));
@@ -457,9 +458,7 @@
 	int i, c, len;
 	u_int mode;
 
-	if (!*buf) return(0);
 	len = strlen(buf);
-
 	if (len < 9) {
 		mode = (tmp -> st_mode & S_IFMT) | S_IREAD_ALL | S_IWRITE_ALL;
 		while (--len >= 0) {
@@ -547,7 +546,7 @@
 	}
 
 	tmp -> st_mode = mode;
-	return(1);
+	return(len);
 }
 
 #if	FD >= 2
@@ -836,21 +835,24 @@
 				err = 0;
 				break;
 			default:
-				free(buf);
-				free(rawbuf);
-				if (tmp -> name) free(tmp -> name);
+				hit = -1;
+				break;
+		}
+
+		free(buf);
+		free(rawbuf);
+
+		if (hit < 0) {
+			if (tmp -> name) free(tmp -> name);
 # ifndef	NOSYMLINK
-				if (tmp -> linkname) free(tmp -> linkname);
+			if (tmp -> linkname) free(tmp -> linkname);
 # endif
-				return(-1);
-/*NOTREACHED*/
-				break;
+			return(hit);
 		}
+
 		if (!hit) score += 5;
 		else if (hit <= err2) score += err2;
 		score += err;
-		free(buf);
-		free(rawbuf);
 		line += len;
 		if (!ch) while (iswhitespace(*line)) line++;
 	}
@@ -1024,7 +1026,7 @@
 	tmp -> name = strdup2(buf);
 
 	getfield(buf, line, skip, list, F_MODE);
-	if (!readattr(tmp, buf)) tmp -> st_mode = 0644;
+	readattr(tmp, buf);
 	if (!(tmp -> st_mode & S_IFMT)) tmp -> st_mode |= S_IFREG;
 	if (s_isdir(tmp)) tmp -> flags |= F_ISDIR;
 	else if (s_islnk(tmp)) tmp -> flags |= F_ISLNK;
@@ -1241,15 +1243,14 @@
 static char *NEAR pseudodir(namep)
 namelist *namep;
 {
-	char *cp, *tmp;
+	char *cp, *next;
 	int i, len;
 	u_short ent;
 
-	cp = namep -> name;
-	while ((tmp = strdelim(cp, 0))) {
-		while (*(tmp + 1) == _SC_) tmp++;
-		if (!*(tmp + 1)) break;
-		len = tmp - (namep -> name);
+	for (cp = namep -> name; (next = strdelim(cp, 0)); cp = next + 1) {
+		while (*(next + 1) == _SC_) next++;
+		if (!*(next + 1)) break;
+		len = next - namep -> name;
 		if (!len) len++;
 		for (i = 0; i < maxfile; i++) {
 			if (isdir(&(filelist[i]))
@@ -1261,21 +1262,22 @@
 			filelist[i].name = realloc2(filelist[i].name, len + 1);
 			strncpy2(filelist[i].name, namep -> name, len);
 		}
-		cp = tmp + 1;
 	}
+
 	if (isdir(namep) && !isdotdir(namep -> name))
 	for (i = 0; i < maxfile; i++) {
 		if (isdir(&(filelist[i]))
 		&& !dircmp(filelist[i].name, namep -> name)) {
-			tmp = filelist[i].name;
+			cp = filelist[i].name;
 			ent = filelist[i].ent;
 			memcpy((char *)&(filelist[i]), (char *)namep,
 				sizeof(namelist));
-			filelist[i].name = tmp;
+			filelist[i].name = cp;
 			filelist[i].ent = ent;
 			return(NULL);
 		}
 	}
+
 	return(namep -> name);
 }
 
@@ -1609,7 +1611,7 @@
 #ifndef	NOSYMLINK
 	filelist[0].linkname = NULL;
 #endif
-	filelist[0].flags = F_ISDIR;
+	filelist[0].flags = (F_ISDIR | F_ISRED | F_ISWRI);
 	filelist[0].tmpflags = F_STAT;
 	maxfile++;
 #ifdef	HAVEFLAGS
@@ -1713,25 +1715,26 @@
 char *arcre;
 {
 	char *cp, *tmp;
-	int i, j, n, len;
+	int i, j, n, len, parent;
 
+	parent = (*archivedir) ? 0 : -1;
+	/* omit filelist[0] as pseudo ".." */
 	for (i = 1; i < maxarcf; i++) {
 		if (!*archivedir) len = 0;
 		else if (!(len = dirmatchlen(archivedir, arcflist[i].name)))
 			continue;
 
-		cp = arcflist[i].name + len;
-		if (len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
-		if (!arcflist[i].name[len]) {
-			memcpy((char *)&(filelist[0]),
-				(char *)&(arcflist[i]), sizeof(namelist));
-			filelist[0].name = arcflist[0].name;
-#ifndef	NOSYMLINK
-			filelist[0].linkname = NULL;
-#endif
+		cp = &(arcflist[i].name[len]);
+		if (*cp && len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
+		if (!*cp) {
+			parent = i;
 			continue;
 		}
-		if ((tmp = strdelim(cp, 0))) while (*(++tmp) == _SC_);
+		if ((tmp = strdelim(cp, 0))) {
+			if (tmp - cp == 2 && cp[0] == '.' && cp[1] == '.')
+				if (parent <= 0) parent = i;
+			while (*(++tmp) == _SC_);
+		}
 		if ((tmp && *tmp) || (re && !regexp_exec(re, cp, 1))) continue;
 		if (arcre) {
 			if (!(n = searcharc(arcre, arcflist, maxarcf, i)))
@@ -1751,6 +1754,18 @@
 #endif
 		maxfile++;
 	}
+
+	if (parent < 0) return;
+	for (i = 0; i < maxfile; i++)
+		if (!strcmp(filelist[i].name, "..")) return;
+	memmove((char *)&(filelist[1]), (char *)&(filelist[0]),
+		maxfile++ * sizeof(namelist));
+	memcpy((char *)&(filelist[0]),
+		(char *)&(arcflist[parent]), sizeof(namelist));
+	filelist[0].name = arcflist[0].name;
+#ifndef	NOSYMLINK
+	filelist[0].linkname = NULL;
+#endif
 }
 
 static char *NEAR searcharcdir(file, flen)
@@ -1761,14 +1776,14 @@
 	int i, len;
 
 	errno = ENOENT;
-	for (i = 1; i < maxarcf; i++) {
+	for (i = 0; i < maxarcf; i++) {
 		if (!*archivedir) len = 0;
 		else if (!(len = dirmatchlen(archivedir, arcflist[i].name)))
 			continue;
 
-		cp = arcflist[i].name + len;
-		if (len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
-		if (!arcflist[i].name[len]) {
+		cp = &(arcflist[i].name[len]);
+		if (*cp && len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
+		if (!*cp) {
 			if (file) continue;
 		}
 		else {
@@ -1778,6 +1793,8 @@
 				len = (tmp == cp) ? 1 : tmp - cp;
 				while (*(++tmp) == _SC_);
 			}
+			if (!*file && len == 2 && cp[0] == '.' && cp[1] == '.')
+				return(arcflist[0].name);
 			if ((tmp && *tmp) || len != flen
 			|| strnpathcmp(file, cp, flen))
 				continue;
@@ -1791,6 +1808,29 @@
 	return(NULL);
 }
 
+static char *NEAR archoutdir(VOID_A)
+{
+	char *cp, *file;
+
+	if (!*archivedir) return((char *)-1);
+	if (!(file = searcharcdir(NULL, 0))) return(NULL);
+
+	cp = file + (int)strlen(file) - 1;
+	while (cp > file && *cp == _SC_) cp--;
+#ifdef	BSPATHDELIM
+	if (onkanji1(file, cp - file)) cp++;
+#endif
+	cp = strrdelim2(file, cp);
+	if (!cp) *archivedir = '\0';
+	else {
+		if (cp == file) strcpy(archivedir, _SS_);
+		else strncpy2(archivedir, file, cp - file);
+		file = cp + 1;
+	}
+
+	return(file);
+}
+
 char *archchdir(path)
 char *path;
 {
@@ -1799,11 +1839,11 @@
 
 	if (findpattern) free(findpattern);
 	findpattern = NULL;
-	if (!path || !*path) path = "..";
 #ifndef	_NOBROWSE
 	if (browselist) {
 		int i, n, dupfilepos;
 
+		if (!path || !*path) path = "..";
 		if ((cp = strdelim(path, 0))) {
 			for (i = 1; cp[i]; i++) if (cp[i] != _SC_) break;
 			if (cp[i]) {
@@ -1846,43 +1886,28 @@
 		return("..");
 	}
 #endif	/* !_NOBROWSE */
+
+	if (!path) return(archoutdir());
 	strcpy(duparcdir, archivedir);
 	do {
 		if (*path == _SC_) len = 1;
 		else if ((cp = strdelim(path, 0))) len = cp - path;
 		else len = strlen(path);
 
-		if (len == 1 && *path == '.') file = "..";
-		else if (len != 2 || strncmp(path, "..", len)) {
-			if (!searcharcdir(path, len)) {
-				strcpy(archivedir, duparcdir);
-				errno = ENOENT;
-				return(NULL);
-			}
+		cp = path;
+		if (len == 2 && path[0] == '.' && path[1] == '.') cp = "";
+		if (searcharcdir(cp, len)) {
 			if (*(cp = archivedir)) cp = strcatdelim(archivedir);
 			strncpy2(cp, path, len);
 			file = "..";
 		}
-		else if (!*archivedir) return((char *)-1);
-		else {
-			if (!(file = searcharcdir(NULL, 0))) {
-				strcpy(archivedir, duparcdir);
-				errno = ENOENT;
-				return(NULL);
-			}
-			cp = file + (int)strlen(file) - 1;
-			while (cp > file && *cp == _SC_) cp--;
-#ifdef	BSPATHDELIM
-			if (onkanji1(file, cp - file)) cp++;
-#endif
-			cp = strrdelim2(file, cp);
-			if (!cp) *archivedir = '\0';
-			else {
-				if (cp == file) strcpy(archivedir, _SS_);
-				else strncpy2(archivedir, file, cp - file);
-				file = cp + 1;
-			}
+		else if (*cp || !(file = archoutdir())) {
+			strcpy(archivedir, duparcdir);
+			errno = ENOENT;
+			return(NULL);
 		}
+		else if (file == (char *)-1) break;
+
 		path += len;
 		while (*path == _SC_) path++;
 	} while (*path);
@@ -1897,7 +1922,7 @@
 char ***argvp;
 {
 	char *cp, *tmp, *new, *file, dir[MAXPATHLEN], duparcdir[MAXPATHLEN];
-	int i, len;
+	int i, len, parent;
 
 # ifdef	_USEDOSPATH
 	if (_dospath(path)) return(argc);
@@ -1917,25 +1942,35 @@
 		flen -= ++file - path;
 	}
 
+	/* omit filelist[0] as pseudo ".." */
 	for (i = 1; i < maxarcf; i++) {
 		if (!*archivedir) len = 0;
 		else if (!(len = dirmatchlen(archivedir, arcflist[i].name)))
 			continue;
 
-		cp = arcflist[i].name + len;
-		if (len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
-		if (!arcflist[i].name[len]) continue;
+		cp = &(arcflist[i].name[len]);
+		if (*cp && len > 0 && (len > 1 || *archivedir != _SC_)) cp++;
+		if (!*cp) continue;
 
 		if (!(tmp = strdelim(cp, 0))) len = strlen(cp);
 		else {
 			len = (tmp == cp) ? 1 : tmp - cp;
 			while (*(++tmp) == _SC_);
 		}
-		if ((tmp && *tmp) || strnpathcmp(file, cp, flen)) continue;
+
+		parent = 0;
+		if (len == 2 && cp[0] == '.' && cp[1] == '.') {
+			if (strnpathcmp(file, cp, flen)) continue;
+			parent++;
+		}
+		else {
+			if ((tmp && *tmp) || strnpathcmp(file, cp, flen))
+				continue;
+		}
 
 		new = malloc2(len + 1 + 1);
 		strncpy(new, cp, len);
-		if (isdir(&(arcflist[i]))) new[len++] = _SC_;
+		if (parent || isdir(&(arcflist[i]))) new[len++] = _SC_;
 		new[len] = '\0';
 		if (finddupl(new, argc, *argvp)) {
 			free(new);
