--- bjc250/src/gdevbjca.c.orig	Fri Nov  8 06:15:15 2002
+++ bjc250/src/gdevbjca.c	Fri Nov  8 07:47:41 2002
@@ -46,10 +46,10 @@
 #include <math.h>
 #include <time.h>
 
-private void bjc_put_bytes(P3(FILE *file, const char *data, int count));
-private void bjc_put_hi_lo(P2(FILE *file, int value));
-private void bjc_put_lo_hi(P2(FILE *file, int value));
-private void bjc_put_command(P3(FILE *file, char command, int count));
+private void bjc_put_bytes(FILE *file, const char *data, int count);
+private void bjc_put_hi_lo(FILE *file, int value);
+private void bjc_put_lo_hi(FILE *file, int value);
+private void bjc_put_command(FILE *file, char command, int count);
 
 /* ---------------- Utilities ---------------- */
 
