--- guile-gnome/ghttp/ghttp-glue.c.orig	Sat Aug 31 14:07:19 2002
+++ guile-gnome/ghttp/ghttp-glue.c	Sat Aug 31 14:08:23 2002
@@ -53,7 +53,7 @@
 };
 
 GtkTypeInfo sgtk_ghttp_request_info_gtk = {
-  "ghttprequest", "sizeof (ghttp_request)", 0,
+  "ghttprequest", 0, 0,
   (GtkClassInitFunc) NULL,
   (GtkObjectInitFunc) NULL,
   (GtkArgSetFunc) NULL,
