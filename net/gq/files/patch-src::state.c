--- src/state.c.orig	Thu Jul 29 09:44:27 2004
+++ src/state.c	Thu Jul 29 09:44:51 2004
@@ -754,7 +754,7 @@
 	}
     }
 
-    if (n != NULL && v->type != 0) {
+    if (n != NULL && v!=NULL && v->type != 0) {
 	char *ep;
 
 	assert(v);
