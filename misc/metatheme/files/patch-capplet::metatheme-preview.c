--- capplet/metatheme-preview.c.orig	Fri Nov 10 20:59:14 2000
+++ capplet/metatheme-preview.c	Thu Apr 19 14:23:34 2001
@@ -195,3 +195,3 @@
 		case ARG_HAS_FOCUS:
-			e_canvas_item_grab_focus (item);
+			e_canvas_item_grab_focus (item, TRUE);
 			break;
@@ -378,3 +378,3 @@
 			if (event->button.button == 1)
-				e_canvas_item_grab_focus (item);
+				e_canvas_item_grab_focus (item, TRUE);
 			break;
@@ -474,3 +474,3 @@
 
-	e_canvas_item_grab_focus (GNOME_CANVAS_ITEM (preview));
+	e_canvas_item_grab_focus (GNOME_CANVAS_ITEM (preview), TRUE);
 }
