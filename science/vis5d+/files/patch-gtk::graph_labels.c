--- gtk/graph_labels.c.orig	Fri Aug 20 19:36:36 2004
+++ gtk/graph_labels.c	Fri Aug 20 19:37:04 2004
@@ -169,6 +169,7 @@
 		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(widget), FALSE);
       break;
 	 default:
+		break;
 	 }
 	 break;
   case VSLICE:
