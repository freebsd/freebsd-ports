cf. [FDclone-users:00493]

diff -u ../old/FD-2.08b/shell.c ./shell.c
--- ../old/FD-2.08b/shell.c	Thu Mar 30 00:00:00 2006
+++ ./shell.c	Mon Apr 10 22:45:35 2006
@@ -1630,12 +1630,7 @@
 	int i, j, size;
 
 	if (!file || !(fp = Xfopen(file, "r"))) return(-1);
-#ifndef	NOFLOCK
-	if (lockfile(Xfileno(fp), LCK_READ) < 0) {
-		Xfclose(fp);
-		return(-1);
-	}
-#endif
+	VOID_C lockfile(Xfileno(fp), LCK_READ);
 
 	size = (int)histsize[n];
 	history[n] = (char **)malloc2(sizeof(char *) * (size + 1));
@@ -1650,7 +1645,7 @@
 		for (j = i; j > 0; j--) history[n][j] = history[n][j - 1];
 		history[n][0] = line;
 	}
-	lockfile(Xfileno(fp), LCK_UNLOCK);
+	VOID_C lockfile(Xfileno(fp), LCK_UNLOCK);
 	Xfclose(fp);
 
 	for (i++; i <= size; i++) history[n][i] = NULL;
@@ -1684,16 +1679,11 @@
 
 	if (!history[n] || !history[n][0]) return(-1);
 	if (!file || !(fp = Xfopen(file, "w"))) return(-1);
-#ifndef	NOFLOCK
-	if (lockfile(Xfileno(fp), LCK_WRITE) < 0) {
-		Xfclose(fp);
-		return(-1);
-	}
-#endif
+	VOID_C lockfile(Xfileno(fp), LCK_WRITE);
 
 	size = (savehist > (int)histsize[n]) ? (int)histsize[n] : savehist;
 	for (i = size - 1; i >= 0; i--) convhistory(history[n][i], fp);
-	lockfile(Xfileno(fp), LCK_UNLOCK);
+	VOID_C lockfile(Xfileno(fp), LCK_UNLOCK);
 	Xfclose(fp);
 
 	return(0);
