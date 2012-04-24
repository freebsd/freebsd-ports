Patch taken from [FDclone-users:00977].

diff -ur ../old/FD-3.00k/archive.c ./archive.c
--- ../old/FD-3.00k/archive.c	Sat Apr 21 00:00:00 2012
+++ ./archive.c	Sun Apr 22 19:33:51 2012
@@ -969,8 +969,7 @@
 		poparchdupl();
 		return(-1);
 	}
-	maxfile = 0;
-	filepos = -1;
+	maxfile = filepos = 0;
 
 	return(1);
 }
