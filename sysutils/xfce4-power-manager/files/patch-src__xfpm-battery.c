--- ./src/xfpm-battery.c.orig	2011-02-15 08:58:47.000000000 -0500
+++ ./src/xfpm-battery.c	2011-05-29 14:46:28.720111315 -0400
@@ -144,6 +144,8 @@
 	    visible = FALSE;
 	else visible = TRUE;
     }
+    if ( battery->priv->state == XFPM_DEVICE_STATE_UNKNOWN )
+	    visible = FALSE;
 
     XFPM_DEBUG_ENUM (show_icon, XFPM_TYPE_SHOW_ICON, "visible=%s", xfpm_bool_to_string (visible));
 			  
@@ -537,13 +539,18 @@
     }
     
     state = g_value_get_uint (value);
+
     if ( state != battery->priv->state )
     {
 	battery->priv->state = state;
 	xfpm_battery_refresh_visible (battery);
 	xfpm_battery_notify_state (battery);
     }
-    
+    else {
+        if ( battery->priv->state == XFPM_DEVICE_STATE_UNKNOWN )
+	    goto out;
+    } 
+
     value = g_hash_table_lookup (props, "Percentage");
     
     if ( value == NULL )
@@ -896,6 +903,13 @@
     return battery->priv->battery_name;
 }
 
+XfpmDeviceState xfpm_battery_get_device_state (XfpmBattery *battery)
+{
+    g_return_val_if_fail (XFPM_IS_BATTERY (battery), XFPM_DEVICE_STATE_UNKNOWN);
+    
+    return battery->priv->state;
+}
+
 gchar *xfpm_battery_get_time_left (XfpmBattery *battery)
 {
     g_return_val_if_fail (XFPM_IS_BATTERY (battery), NULL);
