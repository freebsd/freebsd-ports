--- libegg/toolbar/eggtoolbar.c.orig	Thu Aug 12 10:09:55 2004
+++ libegg/toolbar/eggtoolbar.c	Thu Aug 12 10:11:54 2004
@@ -2534,7 +2534,7 @@
 
 GtkWidget*
 egg_toolbar_append_element (EggToolbar          *toolbar,
-			    GtkToolbarChildType  type,
+			    EggToolbarChildType  type,
 			    GtkWidget           *widget,
 			    const char          *text,
 			    const char          *tooltip_text,
@@ -2551,7 +2551,7 @@
 
 GtkWidget *
 egg_toolbar_prepend_element (EggToolbar          *toolbar,
-			     GtkToolbarChildType  type,
+			     EggToolbarChildType  type,
 			     GtkWidget           *widget,
 			     const char          *text,
 			     const char          *tooltip_text,
