--- src/interface.c.orig	Wed Dec  1 13:23:26 2004
+++ src/interface.c	Wed Dec  1 13:24:00 2004
@@ -529,12 +529,12 @@
 
 	model = gtk_tree_store_new (10,
 				    GDK_TYPE_PIXBUF,
-				    G_TYPE_STRING, // device name
-				    G_TYPE_STRING, // directory
-				    G_TYPE_STRING, // type
-				    G_TYPE_STRING, // total
-				    G_TYPE_STRING, // free
-				    G_TYPE_STRING, // used
+				    G_TYPE_STRING, /* device name */
+				    G_TYPE_STRING, /* directory */
+				    G_TYPE_STRING, /* type */
+				    G_TYPE_STRING, /* total */
+				    G_TYPE_STRING, /* free */
+				    G_TYPE_STRING, /* used */
 				    G_TYPE_FLOAT,
 				    G_TYPE_FLOAT,
 				    G_TYPE_FLOAT);
