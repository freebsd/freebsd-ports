
$FreeBSD$

--- src/flow-dscan.c.orig	Tue Aug 24 10:40:32 2004
+++ src/flow-dscan.c	Tue Aug 24 10:41:01 2004
@@ -561,8 +561,9 @@
 
 skip2:
 
+	;
 
-  } /* while rec */
+	} /* while rec */
 
   if (debug > 0) {
     ftprof_end(&ftp, ftio_get_rec_total(&ftio));
@@ -806,8 +807,8 @@
   fterr_info("ager: reset hash run");
 
 skip3:
-
-} /* ager */
+	;
+	} /* ager */
 
 int load_suppress(struct dscan_state *ds, int sd)
 {
