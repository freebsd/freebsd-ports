--- runtime/libgcry.c.ori	2013-05-24 20:24:27.000000000 -0600
+++ runtime/libgcry.c	2013-05-24 20:24:52.000000000 -0600
@@ -171,7 +171,7 @@
  * no matter what happens.
  */
 static void
-eiClose(gcryfile gf, off64_t offsLogfile)
+eiClose(gcryfile gf, off_t offsLogfile)
 {
 	char offs[21];
 	size_t len;
@@ -213,7 +213,7 @@
 }
 
 int
-gcryfileDestruct(gcryfile gf, off64_t offsLogfile)
+gcryfileDestruct(gcryfile gf, off_t offsLogfile)
 {
 	int r = 0;
 	if(gf == NULL)
