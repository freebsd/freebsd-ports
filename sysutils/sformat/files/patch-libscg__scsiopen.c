--- libscg/scsiopen.c.orig	Sun Mar 18 14:54:18 2001
+++ libscg/scsiopen.c	Tue May 20 22:58:07 2003
@@ -239,7 +239,7 @@
 	}
 	if (scg__open(scgp, devname) <= 0) {
 		if (errs && scgp->errstr)
-			js_snprintf(errs, slen, scgp->errstr);
+			js_snprintf(errs, slen, "%s", scgp->errstr);
 		scg_sfree(scgp);
 		return ((SCSI *)0);
 	}
