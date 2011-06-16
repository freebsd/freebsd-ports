--- ./src/xfpm-power.c.orig	2011-02-15 15:30:04.000000000 -0500
+++ ./src/xfpm-power.c	2011-05-29 19:25:21.634588113 -0400
@@ -1028,6 +1028,9 @@
 	g_signal_connect (battery, "battery-charge-changed",
 			  G_CALLBACK (xfpm_power_battery_charge_changed_cb), power);
 			  
+        g_signal_connect_swapped (battery, "battery-charge-changed",
+			      G_CALLBACK (xfpm_power_refresh_adaptor_visible), power);
+
 	xfpm_power_refresh_adaptor_visible (power);
     }
     else if ( device_type != XFPM_DEVICE_TYPE_LINE_POWER )
@@ -1144,6 +1147,11 @@
 xfpm_power_refresh_adaptor_visible (XfpmPower *power)
 {
     XfpmShowIcon show_icon;
+    XfpmDeviceState state;
+    GtkStatusIcon *battery = NULL;
+    gboolean show_adapter_icon;
+    guint i, len;
+    GList *list;
     
     g_object_get (G_OBJECT (power->priv->conf),
 		  SHOW_TRAY_ICON_CFG, &show_icon,
@@ -1153,8 +1161,30 @@
     
     if ( show_icon == SHOW_ICON_ALWAYS )
     {
-	if ( g_hash_table_size (power->priv->hash) == 0 )
+	show_adapter_icon = TRUE;
+	if ( g_hash_table_size (power->priv->hash) != 0 )
 	{
+            /*
+             *  Make sure that a least one battery has a valid state before disabling 
+             *  the adapter icon.
+             */
+            list = g_hash_table_get_values (power->priv->hash);
+            len = g_list_length (list);
+            
+            for ( i = 0; i < len; i++)
+            {
+        	battery = g_list_nth_data (list, i);
+        	state = xfpm_battery_get_device_state(XFPM_BATTERY (battery));
+                if ( state != XFPM_DEVICE_STATE_UNKNOWN )
+                {
+		     show_adapter_icon = FALSE;
+        	     break;
+                }
+            }
+        }
+ 
+	if ( show_adapter_icon )
+        {
 	    xfpm_power_show_adapter_icon (power);
 #if GTK_CHECK_VERSION (2, 16, 0)
 	    gtk_status_icon_set_tooltip_text (power->priv->adapter_icon, 
