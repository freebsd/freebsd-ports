--- stegdetect.c	Sat Jan 26 23:51:16 2002
+++ /tmp/stegdetect.c.diff	Wed Dec 29 03:32:38 2004
@@ -1198,7 +1198,7 @@
 		flag = 1;
 		strlcat(outbuf, " f5(***)", sizeof(outbuf));
 
-	no_f5:
+	no_f5:;
 	}
 
 	if (scans & FLAG_DOINVIS) {
@@ -1237,7 +1237,7 @@
 			strlcat(outbuf, tmp, sizeof(outbuf));
 		}
 		
-	no_invisiblesecrets:
+	no_invisiblesecrets:;
 	}
 
 	if ((scans & FLAG_CHECKHDRS)) {
@@ -1301,7 +1301,7 @@
 		}
 
 		free(dcts);
-	jsteg_error:
+	jsteg_error:;
 	}
 
 	if ((scans & FLAG_DOOUTGUESS) && prepare_normal(&dcts, &bits) != -1) {
