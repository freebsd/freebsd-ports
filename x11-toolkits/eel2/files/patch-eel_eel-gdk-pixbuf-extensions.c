--- eel/eel-gdk-pixbuf-extensions.c.orig	Sun Jul  7 03:24:52 2002
+++ eel/eel-gdk-pixbuf-extensions.c	Sun Jul  7 03:25:03 2002
@@ -101,7 +101,7 @@
 {
 	GnomeVFSResult result;
 	GnomeVFSHandle *handle;
-	char buffer[LOAD_BUFFER_SIZE];
+	static char buffer[LOAD_BUFFER_SIZE];
 	GnomeVFSFileSize bytes_read;
 	GdkPixbufLoader *loader;
 	GdkPixbuf *pixbuf;	
