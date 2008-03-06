--- src/mypopen.c.orig	2008-03-06 21:12:35.000000000 +0100
+++ src/mypopen.c	2008-03-06 21:15:44.000000000 +0100
@@ -108,7 +108,9 @@
 
 int mypclose(FILE *ptr)
 {
-	register f, r, (*hstat)(), (*istat)(), (*qstat)();
+	int f;
+	pid_t r;
+	void (*hstat)(), (*istat)(), (*qstat)();
 	int status;
 
 	f = fileno(ptr);
