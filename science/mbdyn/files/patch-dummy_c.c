--- mbdyn/dummy_c.c~	Thu Jan 19 01:26:09 2006
+++ mbdyn/dummy_c.c	Wed Jan 17 11:12:01 2007
@@ -40,7 +40,7 @@
 dummy_c(void)
 {
 	double a, b;
-	pow_dd(&a, &b);
+//	pow_dd(&a, &b);
 
 #ifdef NEED_F77_IO
 #warning "needed for F77 I/o"
