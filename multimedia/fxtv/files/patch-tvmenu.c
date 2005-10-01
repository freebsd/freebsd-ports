--- tvmenu.c.orig	Fri Sep 23 23:56:25 2005
+++ tvmenu.c	Fri Sep 23 23:56:25 2005
@@ -589,7 +589,7 @@
 
         XtVaSetValues(children[i], XtNleftBitmap, pix, NULL);
 #else
-        if ( strcmp( actual_station, temp_station ) == 0 )
+        if ( strcmp( actual_station, temp_station==NULL ? "" : temp_station ) == 0 )
             new_popup_item = children[i];
 #endif
     }
