--- engines/industrial/src/industrial_style.c.orig	Tue Mar 16 16:55:11 2004
+++ engines/industrial/src/industrial_style.c	Tue Mar 16 16:58:23 2004
@@ -1801,6 +1801,7 @@
 	     gint             width,
 	     gint             height)
 {
+	g_return_if_fail (widget != NULL);
 #if DEBUG
   printf ("draw_shadow: %p %p %s %i %i %i %i\n", widget, window, detail, x, y,
 	  width, height);
