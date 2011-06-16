--- ./src/xfpm-battery.h.orig	2011-02-15 04:53:05.000000000 -0500
+++ ./src/xfpm-battery.h	2011-05-29 14:46:28.721112321 -0400
@@ -62,6 +62,8 @@
 
 XfpmDeviceType	   	    xfpm_battery_get_device_type (XfpmBattery *battery);
 
+XfpmDeviceState		    xfpm_battery_get_device_state (XfpmBattery *battery);
+
 XfpmBatteryCharge	    xfpm_battery_get_charge      (XfpmBattery *battery);
 
 const gchar 		   *xfpm_battery_get_battery_name(XfpmBattery *battery);
