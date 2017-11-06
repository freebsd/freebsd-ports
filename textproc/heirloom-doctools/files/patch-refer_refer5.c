--- refer/refer5.c.orig	2016-03-09 21:27:38 UTC
+++ refer/refer5.c
@@ -148,14 +148,18 @@ putsig (int nf, char **flds, int nref, c
 			flout();
 			sig[0] = 0;
 			prevsig = 0;
-			if (fo == fhide) {
+			if (fhide != NULL && fo == fhide) {
 				int ch;
 				fclose(fhide); 
 				fhide = fopen(hidenam, "r");
+				if (fhide == NULL)
+					err("Can't get scratch file %s",
+						hidenam);
 				fo = ftemp;
 				while ((ch = getc(fhide)) != EOF)
 					putc(ch, fo);
 				fclose(fhide);
+				fhide = NULL;
 				unlink(hidenam);
 			}
 		}
