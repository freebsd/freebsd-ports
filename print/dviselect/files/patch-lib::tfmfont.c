--- lib/tfmfont.c~	Wed Nov 15 13:20:03 1989
+++ lib/tfmfont.c	Wed Dec 13 23:04:06 2006
@@ -139,7 +139,7 @@
 fail:
 	(void) fclose(fd);
 	if (tfm != NULL) {
-	  free((char *) tfm); (char *) tfm = 0;
+	  free((char *) tfm); tfm = 0;
 	}
 	return (-1);
 }
