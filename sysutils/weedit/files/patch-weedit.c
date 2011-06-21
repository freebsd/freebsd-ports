--- ./weedit.c.orig	2011-06-21 15:45:47.000000000 +0200
+++ ./weedit.c	2011-06-21 15:45:23.000000000 +0200
@@ -265,7 +265,7 @@
 	exit (-1);
 }
 
-int main(unsigned int argc, char **argv)
+int main(int argc, char **argv)
 {
 	float timeval;
 	unsigned long i;
