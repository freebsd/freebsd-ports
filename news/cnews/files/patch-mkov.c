--- nov/mkov.c.orig	1994-10-18 04:49:48.000000000 +0100
+++ nov/mkov.c	2014-02-07 16:52:25.000000000 +0100
@@ -176,7 +176,7 @@
 			error("fstat of %s failed", inname);
 		if ((statb.st_mode&S_IFMT) == S_IFDIR ||
 		    (oldtime > 0 && statb.st_mtime > oldtime))
-			return;		/* ignore directories and new files */
+			return 0;		/* ignore directories and new files */
 		artnumstr = base;
 		(void) sprintf(bytes, "%ld", (long)statb.st_size);
 	}
@@ -212,6 +212,7 @@
 
 		freehdrs(&hdrs);
 	} while (!articles && hdr != NULL);
+	return 0;
 }
 
 char *					/* NULL at EOF, or malloced, don't free */
