--- nawk/main.c.orig	2012-12-03 10:03:30.000000000 +0100
+++ nawk/main.c	2012-12-03 10:03:51.000000000 +0100
@@ -66,7 +66,7 @@
 
 extern const char badopen[];
 
-int main(int argc, unsigned char *argv[], unsigned char *envp[])
+int main(int argc, char *argv[], char *envp[])
 {
 	unsigned char *fs = NULL;
 	char label[MAXLABEL+1];	/* Space for the catalogue label */
