Taken from: [FDclone-users:00145]

diff -u ../old/FD-2.03a/shell.c ./shell.c
--- ../old/FD-2.03a/shell.c	Tue Apr 15 00:00:00 2003
+++ ./shell.c	Tue Apr 22 00:00:00 2003
@@ -752,6 +752,11 @@
 	*argcp = argc = argc2;
 	*argvp = argv = argv2;
 
+	if (iscomm < 0) {
+		free(buf);
+		return(ret);
+	}
+
 	min = -1;
 	for (next = lastptr; next < maxfile; next++)
 	if (isarg(&(filelist[next]))) {
@@ -767,7 +772,7 @@
 			if (!isneedmark(argv[n], i)) buf[j++] = argv[n][i];
 			else {
 				flags = argv[n][++i];
-				cp = (iscomm < 0 || n) ? arg : NULL;
+				cp = (!env || n) ? arg : NULL;
 				if (min >= 0 && next < maxfile) ret++;
 
 				len = setarg(&buf, j, &size, NULL, cp, flags);
