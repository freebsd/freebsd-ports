--- scsilib/libscg/scsiopen.c.orig	Sun Nov 25 16:35:10 2001
+++ scsilib/libscg/scsiopen.c	Tue May 20 23:01:01 2003
@@ -239,7 +239,7 @@
 	}
 	if (scg__open(scgp, devname) <= 0) {
 		if (errs && scgp->errstr)
-			js_snprintf(errs, slen, scgp->errstr);
+			js_snprintf(errs, slen, "%s", scgp->errstr);
 		scg_sfree(scgp);
 		return ((SCSI *)0);
 	}
