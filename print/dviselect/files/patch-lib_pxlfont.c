--- lib/pxlfont.c~	Wed Nov 15 13:19:53 1989
+++ lib/pxlfont.c	Wed Dec 13 23:03:21 2006
@@ -156,7 +156,7 @@
 		if (pd->pd_ras) {
 		  free(pd->pd_ras); pd->pd_ras = 0;
 		}
-		free((char *) pd); (char *) pd = 0;
+		free((char *) pd); pd = 0;
 	}
 	if (fp)
 		(void) fclose(fp);
@@ -286,7 +286,7 @@
 	pd->pd_nconv += h - l;
 	if (pd->pd_nconv == 128) {
 		free(pd->pd_ras); pd->pd_ras = 0;
-		free((char *) pd); (char *) pd = 0;
+		free((char *) pd); pd = 0;
 		f->f_details = NULL;
 	}
 	return (0);
@@ -305,6 +305,6 @@
 		if (pd->pd_ras != NULL) {
 		  free(pd->pd_ras); pd->pd_ras = 0;
 		}
-		free((char *) pd); (char *) pd = 0;
+		free((char *) pd); pd = 0;
 	}
 }
