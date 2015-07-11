--- chkwtmp.c.orig	2014-05-06 10:13:16 UTC
+++ chkwtmp.c
@@ -19,7 +19,7 @@
    Nelson Murilo, nelson@pangeia.com.br
 */
 
-#if __FreeBSD__ > 9 
+#if __FreeBSD__ >= 9 
 int main () { return 0; } 
 #else
 #include <stdio.h>
