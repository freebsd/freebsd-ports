--- src/sdig.h.orig	2021-10-08 14:08:41 UTC
+++ src/sdig.h
@@ -42,14 +42,6 @@ typedef struct {
 	void    *next;
 }       pdtype;
 
-/* holds the results of a matched port */
-struct result {
-	stype s;
-	char *ifIdx;
-	char *ifAlias;
-	char *ifName;
-} result;
-
 /*
  * global data
  */
