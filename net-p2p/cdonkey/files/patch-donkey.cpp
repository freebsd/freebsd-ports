--- donkey.cpp.orig	Wed May  7 20:26:57 2003
+++ donkey.cpp	Thu Aug 26 18:51:54 2004
@@ -935,7 +935,6 @@
 
 int main (int argc, char **argv) {{{
 	bzero (ZERO, 16);
-	mtrace ();	// MALLOC_TRACE
 	struct stat dStatBuf;
 	int j = 0;
 
