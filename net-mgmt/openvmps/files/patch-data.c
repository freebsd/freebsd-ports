--- data.c.orig	2012-11-10 16:26:08.000000000 +0100
+++ data.c	2012-11-10 16:27:30.000000000 +0100
@@ -37,7 +37,7 @@
 
 void *xfree(void *p) {
 
-	if (p == NULL) return;
+	if (p == NULL) return NULL;
 	vmps_log(DEBUG|SYSTEM, "FREE: %x",p);
 	free(p);
 }
