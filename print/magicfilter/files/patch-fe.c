--- fe.c.orig	2003-05-09 18:27:15 UTC
+++ fe.c
@@ -128,7 +128,7 @@ be(int input, int output)
 
     /* read rules
      */
-    while ( (r = getline(f)) != 0) {
+    while ( (r = get_line(f)) != 0) {
 	rulecount++;
 	if (tail) {
 	    tail->next = r;
