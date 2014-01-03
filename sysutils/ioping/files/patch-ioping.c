--- ioping.c.orig	2014-01-03 10:36:08.000000000 +0400
+++ ioping.c	2014-01-03 10:36:48.000000000 +0400
@@ -247,7 +247,7 @@
 
 void version(void)
 {
-	fprintf(stderr, "ioping %s\n", VERSION);
+	fprintf(stderr, "ioping %f\n", VERSION);
 }
 
 struct suffix {
