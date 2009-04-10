--- gtk/gtkscalebutton.c	2009/03/06 14:06:46	22478
+++ gtk/gtkscalebutton.c	2009/03/18 21:19:07	22574
@@ -119,6 +119,8 @@
 						 guint                prop_id,
 						 GValue              *value,
 						 GParamSpec          *pspec);
+static void gtk_scale_button_set_orientation_private (GtkScaleButton *button,
+                                                      GtkOrientation  orientation);
 static gboolean	gtk_scale_button_scroll		(GtkWidget           *widget,
 						 GdkEventScroll      *event);
 static void gtk_scale_button_screen_changed	(GtkWidget           *widget,
@@ -434,7 +436,7 @@
   switch (prop_id)
     {
     case PROP_ORIENTATION:
-      gtk_scale_button_set_orientation (button, g_value_get_enum (value));
+      gtk_scale_button_set_orientation_private (button, g_value_get_enum (value));
       break;
     case PROP_VALUE:
       gtk_scale_button_set_value (button, g_value_get_double (value));
@@ -739,54 +741,9 @@
 gtk_scale_button_set_orientation (GtkScaleButton *button,
                                   GtkOrientation  orientation)
 {
-  GtkScaleButtonPrivate *priv;
-
   g_return_if_fail (GTK_IS_SCALE_BUTTON (button));
 
-  priv = button->priv;
-
-  if (orientation != priv->orientation)
-    {
-      priv->orientation = orientation;
-
-      gtk_orientable_set_orientation (GTK_ORIENTABLE (priv->box),
-                                      orientation);
-      gtk_container_child_set (GTK_CONTAINER (priv->box),
-                               button->plus_button,
-                               "pack-type",
-                               orientation == GTK_ORIENTATION_VERTICAL ?
-                               GTK_PACK_START : GTK_PACK_END,
-                               NULL);
-      gtk_container_child_set (GTK_CONTAINER (priv->box),
-                               button->minus_button,
-                               "pack-type",
-                               orientation == GTK_ORIENTATION_VERTICAL ?
-                               GTK_PACK_END : GTK_PACK_START,
-                               NULL);
-
-      gtk_orientable_set_orientation (GTK_ORIENTABLE (priv->scale),
-                                      orientation);
-
-      if (orientation == GTK_ORIENTATION_VERTICAL)
-        {
-          gtk_widget_set_size_request (GTK_WIDGET (priv->scale),
-                                       -1, SCALE_SIZE);
-          gtk_range_set_inverted (GTK_RANGE (priv->scale), TRUE);
-        }
-      else
-        {
-          gtk_widget_set_size_request (GTK_WIDGET (priv->scale),
-                                       SCALE_SIZE, -1);
-          gtk_range_set_inverted (GTK_RANGE (priv->scale), FALSE);
-        }
-
-      /* FIXME: without this, the popup window appears as a square
-       * after changing the orientation
-       */
-      gtk_window_resize (GTK_WINDOW (priv->dock), 1, 1);
-
-      g_object_notify (G_OBJECT (button), "orientation");
-    }
+  gtk_scale_button_set_orientation_private (button, orientation);
 }
 
 /**
@@ -843,6 +800,56 @@
   return button->priv->dock;
 }
 
+static void
+gtk_scale_button_set_orientation_private (GtkScaleButton *button,
+                                          GtkOrientation  orientation)
+{
+  GtkScaleButtonPrivate *priv = button->priv;
+
+  if (orientation != priv->orientation)
+    {
+      priv->orientation = orientation;
+
+      gtk_orientable_set_orientation (GTK_ORIENTABLE (priv->box),
+                                      orientation);
+      gtk_container_child_set (GTK_CONTAINER (priv->box),
+                               button->plus_button,
+                               "pack-type",
+                               orientation == GTK_ORIENTATION_VERTICAL ?
+                               GTK_PACK_START : GTK_PACK_END,
+                               NULL);
+      gtk_container_child_set (GTK_CONTAINER (priv->box),
+                               button->minus_button,
+                               "pack-type",
+                               orientation == GTK_ORIENTATION_VERTICAL ?
+                               GTK_PACK_END : GTK_PACK_START,
+                               NULL);
+
+      gtk_orientable_set_orientation (GTK_ORIENTABLE (priv->scale),
+                                      orientation);
+
+      if (orientation == GTK_ORIENTATION_VERTICAL)
+        {
+          gtk_widget_set_size_request (GTK_WIDGET (priv->scale),
+                                       -1, SCALE_SIZE);
+          gtk_range_set_inverted (GTK_RANGE (priv->scale), TRUE);
+        }
+      else
+        {
+          gtk_widget_set_size_request (GTK_WIDGET (priv->scale),
+                                       SCALE_SIZE, -1);
+          gtk_range_set_inverted (GTK_RANGE (priv->scale), FALSE);
+        }
+
+      /* FIXME: without this, the popup window appears as a square
+       * after changing the orientation
+       */
+      gtk_window_resize (GTK_WINDOW (priv->dock), 1, 1);
+
+      g_object_notify (G_OBJECT (button), "orientation");
+    }
+}
+
 /*
  * button callbacks.
  */
