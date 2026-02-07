--- weedit.c.orig	2016-03-25 20:56:46 UTC
+++ weedit.c
@@ -265,7 +265,7 @@ void usage(char *fname)
 	exit (-1);
 }
 
-int main(unsigned int argc, char **argv)
+int main(int argc, char **argv)
 {
 	float timeval;
 	unsigned long i;
