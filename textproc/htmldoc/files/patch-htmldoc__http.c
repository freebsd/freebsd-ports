--- ./htmldoc/http.c.orig	2014-01-05 21:41:32.000000000 +0100
+++ ./htmldoc/http.c	2014-01-28 04:47:07.000000000 +0100
@@ -1228,6 +1228,8 @@
   * Using the current time is a dubious random seed, but on some systems
   * it is the best we can do (on others, this seed isn't even used...)
   */
+#define CUPS_RAND() arc4random()
+#define CUPS_SRAND(v)
 
   CUPS_SRAND(time(NULL));
 
