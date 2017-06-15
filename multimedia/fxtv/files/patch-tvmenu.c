--- tvmenu.c.orig	2001-02-12 21:19:33 UTC
+++ tvmenu.c
@@ -552,7 +552,7 @@ static void TVTOOLSUpdateStationPopup()
     Widget popup_win, new_popup_item = NULL;
     Cardinal num_children, i;
     WidgetList children;
-    String actual_station, temp_station;
+    String actual_station = NULL, temp_station = NULL;
 #ifdef FIXME
     Pixmap pix;
 #endif
@@ -589,7 +589,7 @@ static void TVTOOLSUpdateStationPopup()
 
         XtVaSetValues(children[i], XtNleftBitmap, pix, NULL);
 #else
-        if ( strcmp( actual_station, temp_station ) == 0 )
+        if ( strcmp( actual_station==NULL ? "" : actual_station, temp_station==NULL ? "" : temp_station ) == 0 )
             new_popup_item = children[i];
 #endif
     }
