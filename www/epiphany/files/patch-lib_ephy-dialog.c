--- lib/ephy-dialog.c.orig	Thu Apr 29 02:42:26 2004
+++ lib/ephy-dialog.c	Thu Apr 29 02:42:46 2004
@@ -584,9 +584,10 @@
 		}
 		else
 		{
+			char *v;
 			gtk_combo_box_set_active (GTK_COMBO_BOX (info->widget), -1);
 
-			char *v = g_strdup_value_contents (value);
+			v = g_strdup_value_contents (value);
 			g_warning ("Value '%s' not found in model for combo %s\n", v, info->id);
 			g_free (v);
 		}
