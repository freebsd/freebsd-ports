--- ssh-askpass-fullscreen.c.orig	2006-01-16 04:49:38.000000000 -0800
+++ ssh-askpass-fullscreen.c	2010-02-04 22:30:32.000000000 -0800
@@ -44,7 +44,7 @@
 #include <gtk/gtk.h>
 
 /* XPM */
-static char *ocean_stripes[] = {
+static const char *ocean_stripes[] = {
 /* columns rows colors chars-per-pixel */
 "64 64 3 1",
 "  c #A0A9C1",
@@ -247,7 +247,7 @@
 	GdkColor color;
 	gchar *str;
         GdkGrabStatus status;
-        int grab_tries;
+        int grab_tries = 0;
         const char *failed;
         
  	grab_server = (getenv("GNOME_SSH_ASKPASS_GRAB_SERVER") != NULL); 
