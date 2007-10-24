--- librarian/rarian-main.c.orig	2007-08-02 16:04:45.000000000 -0400
+++ librarian/rarian-main.c	2007-08-02 16:12:58.000000000 -0400
@@ -212,7 +212,7 @@ past:
     path = getenv ("XDG_DATA_DIRS");
 
     if (!path || !strcmp (path, "")) {
-        path = "/usr/local/share/:/usr/share/";
+        path = "/usr/local/share/";
     }
     cur_path = path;
     do {
