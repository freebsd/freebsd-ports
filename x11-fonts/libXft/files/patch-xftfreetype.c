--- xftfreetype.c.orig	Sun Mar 27 18:51:12 2005
+++ xftfreetype.c	Sun Mar 27 18:51:53 2005
@@ -289,7 +289,8 @@ _XftReleaseFile (XftFtFile *f)
 	if (f->face)
 	    FT_Done_Face (f->face);
     }
-    XftMemFree (XFT_MEM_FILE, sizeof (XftFtFile) + strlen (f->file) + 1);
+    XftMemFree (XFT_MEM_FILE,
+	    sizeof (XftFtFile) + (f->file ? strlen (f->file) + 1 : 0));
     free (f);
 }
 
