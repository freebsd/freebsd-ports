--- libscg/scsiopen.c.orig	Tue May 20 21:47:41 2003
+++ libscg/scsiopen.c	Tue May 20 21:48:28 2003
@@ -270,7 +270,7 @@
 	}
 	if (scg__open(scgp, devname) <= 0) {
 		if (errs && scgp->errstr)
-			js_snprintf(errs, slen, scgp->errstr);
+			js_snprintf(errs, slen, "%s", scgp->errstr);
 		scg_sfree(scgp);
 		return ((SCSI *)0);
 	}
