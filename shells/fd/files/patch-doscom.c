[FDclone-users:00266]
  Properly expand globs like <"/usr/"*> and </usr\/*>.
--- doscom.c.orig	Tue Jan  6 15:36:55 2004
+++ doscom.c	Fri May 21 00:23:39 2004
@@ -1701,7 +1701,7 @@
 		} while (!strchr("ynYN", key));
 		if (key == 'n' || key == 'N') return(RET_SUCCESS);
 	}
-	if (!(wild = evalwild(argv[n]))) {
+	if (!(wild = evalwild(argv[n], 0))) {
 		doserror(argv[n], ER_FILENOTFOUND);
 		return(RET_FAIL);
 	}
@@ -1779,7 +1779,7 @@
 		return(RET_FAIL);
 	}
 
-	if (!(wild = evalwild(argv[1]))) {
+	if (!(wild = evalwild(argv[1], 0))) {
 		doserror(argv[1], ER_FILENOTFOUND);
 		return(RET_FAIL);
 	}
@@ -2190,7 +2190,7 @@
 		copyflag |= CF_VERBOSE;
 	}
 	for (n = 0; n < nf; n++) {
-		if (!(wild = evalwild(arg[n]))) {
+		if (!(wild = evalwild(arg[n], 0))) {
 			if (nf > 1) continue;
 			doserror(arg[n], ER_FILENOTFOUND);
 			ret = RET_FAIL;
