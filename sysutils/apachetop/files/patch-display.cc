--- src/display.cc.orig	Sun Feb 22 22:53:52 2004
+++ src/display.cc	Sun Feb 22 22:54:16 2004
@@ -238,8 +238,12 @@
 	 * I'm fairly sure, realistically, it'll never get high enough to be
 	 * a problem, so uInt should be ok */
 	if (items) free(items); /* get rid of the last one */
-	items = (struct itemlist *)
-	    calloc((unsigned int)items_size, sizeof(itemlist));
+	if (items_size == 0) {
+		items = NULL;
+	} else {
+		items = (struct itemlist *)
+		    calloc((unsigned int)items_size, sizeof(itemlist));
+	}
 	
 	/* another thread may change the contents of cf while we're running,
 	 * and it would be undesirable to have most of this change on us, so
