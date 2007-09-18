--- lib/replace/repdir_getdirentries.c.orig	Fri Sep 14 05:21:51 2007
+++ lib/replace/repdir_getdirentries.c	Fri Sep 14 05:22:13 2007
@@ -129,11 +129,7 @@
 		d->ofs = 0;
 		d->nbytes = 0;
 	}
-	/* this relies on seekpos always being a multiple of
-	   DIR_BUF_SIZE. Is that always true on BSD systems? */
-	if (d->seekpos & (DIR_BUF_SIZE-1)) {
-		abort();
-	}
+	/* abort() */
 	return d->seekpos + d->ofs;
 }
 
