--- Cflow.xs.old	Sun Nov  7 06:42:07 2004
+++ Cflow.xs	Sun Nov  7 06:42:32 2004
@@ -759,7 +759,7 @@
                       uint32_t index;
 #            ifdef OSU /* [ */
 		      struct fttime first, last;
-                      if ((FILE *)0 == fp) {
+                      if (0 <= ftio_check_generic(&fs)) {
 		         fdata = ftio_read(&fs);
                          if ((void *)0 == fdata) {
                             break;
