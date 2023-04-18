--- gtk/gtkscale.c.orig	2020-12-18 05:29:40 UTC
+++ gtk/gtkscale.c
@@ -1471,7 +1471,7 @@ gtk_scale_add_mark (GtkScale        *scale,
   mark->position = position;
  
   priv->marks = g_slist_insert_sorted_with_data (priv->marks, mark,
-                                                 (GCompareFunc) compare_marks,
+                                                 (GCompareDataFunc) compare_marks,
                                                  GINT_TO_POINTER (
                                                    gtk_range_get_inverted (GTK_RANGE (scale)) 
                                                    ));
