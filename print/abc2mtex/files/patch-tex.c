--- tex.c.orig	Mon Jan 13 15:04:40 1997
+++ tex.c	Mon May 28 22:34:57 2001
@@ -65,7 +65,7 @@
 	} else (void) fprintf(Out,"\\def\\abcmusix{N}\n");
 	if (settings.mine)
 		(void) fprintf(Out,"\\input dscgrphy\n");
-	(void) fprintf(Out,"\\input header\n%%\n");
+	(void) fprintf(Out,"\\input %s\n%%\n", HEADER);
 	if (musix == 1) (void) fprintf(Out,"\\startmuflex%%\n");
 }
 
