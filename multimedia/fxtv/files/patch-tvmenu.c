--- tvmenu.c.orig	Mon Feb 12 22:19:33 2001
+++ tvmenu.c	Sun Nov 27 01:55:24 2005
@@ -552,7 +552,7 @@
     Widget popup_win, new_popup_item = NULL;
     Cardinal num_children, i;
     WidgetList children;
-    String actual_station, temp_station;
+    String actual_station = NULL, temp_station = NULL;
 #ifdef FIXME
     Pixmap pix;
 #endif
@@ -589,7 +589,7 @@
 
         XtVaSetValues(children[i], XtNleftBitmap, pix, NULL);
 #else
-        if ( strcmp( actual_station, temp_station ) == 0 )
+        if ( strcmp( actual_station==NULL ? "" : actual_station, temp_station==NULL ? "" : temp_station ) == 0 )
             new_popup_item = children[i];
 #endif
     }
