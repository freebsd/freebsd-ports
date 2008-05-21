--- Src/Zle/compresult.c.orig	2008-05-07 10:19:11.000000000 -0300
+++ Src/Zle/compresult.c	2008-05-07 10:19:35.000000000 -0300
@@ -1188,6 +1188,12 @@
 {
     int was_meta;
 
+    /* Just list the matches if the list was requested. */
+    if (lst == COMP_LIST_COMPLETE) {
+	showinglist = -2;
+	return;
+    }
+
     /* Already metafied when called from domenuselect already */
     if (zlemetaline == NULL) {
 	was_meta = 0;
@@ -1195,12 +1201,6 @@
     } else
 	was_meta = 1;
 
-    /* Just list the matches if the list was requested. */
-    if (lst == COMP_LIST_COMPLETE) {
-	showinglist = -2;
-	return;
-    }
-
     /* Otherwise go to the next match in the array... */
     do {
 	if (!*++(minfo.cur)) {
