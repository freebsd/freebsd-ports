--- LocPixmap.c.orig	Wed May 30 21:14:07 2007
+++ LocPixmap.c	Wed May 30 21:14:31 2007
@@ -173,6 +173,7 @@
   } /* if */
 }
 
+static char **split_path_string();
 
 /*
  * XawLocatePixmapFile - read a pixmap file using the normal defaults
@@ -195,7 +196,6 @@
     char **file_paths = NULL;
     char filename[MAXPATHLEN];
     int i;
-    static char **split_path_string();
     char *name;
 
     XpmAttributes attributes;
