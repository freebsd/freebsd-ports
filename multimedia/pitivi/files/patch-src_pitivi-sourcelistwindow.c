--- src/pitivi-sourcelistwindow.c.orig	Mon Dec 20 13:38:58 2004
+++ src/pitivi-sourcelistwindow.c	Mon Dec 20 13:39:54 2004
@@ -1406,9 +1406,10 @@
 	  }
 	else
 	  {
+	    gchar *treepath;
 	    /* we need to set treepath too */
 	    save = g_strdup (self->private->treepath);
-	    gchar *treepath = g_strdup_printf("%s:%d", 
+	    treepath = g_strdup_printf("%s:%d", 
 					      self->private->treepath, 
 					      folder_select);
 	    g_free ( self->private->treepath );
