--- src/stored/ndmp_tape.c	2016-01-27 17:57:48.370956000 -0500
+++ src/stored/ndmp_tape.c	2016-01-27 17:59:50.890336000 -0500
@@ -347,6 +347,16 @@
    DCR *dcr = jcr->dcr;
    POOLMEM *rec_data;
 
+   if (!dcr) {
+      Dmsg0(100, "No dcr defined, bailing out\n");
+      return retval;
+   }
+
+   if (!dcr->rec) {
+      Dmsg0(100, "No dcr->rec defined, bailing out\n");
+      return retval;
+   }
+
    /*
     * Keep track of the original data buffer and restore it on exit from this function.
     */
