--- src/up-device-battery.c.orig	2022-07-21 09:06:49 UTC
+++ src/up-device-battery.c
@@ -19,6 +19,7 @@
  */
 
 #include <string.h>
+#include <math.h>
 
 #include "up-constants.h"
 #include "up-config.h"
@@ -125,7 +126,7 @@ up_device_battery_estimate_power (UpDeviceBattery *sel
 			continue;
 
 		/* Stop searching if the new reference is further away from the long timeout. */
-		if (abs(UP_DAEMON_LONG_TIMEOUT * G_USEC_PER_SEC - abs (td)) > abs(UP_DAEMON_SHORT_TIMEOUT * G_USEC_PER_SEC - ref_td))
+		if (labs(UP_DAEMON_LONG_TIMEOUT * G_USEC_PER_SEC - labs (td)) > labs(UP_DAEMON_SHORT_TIMEOUT * G_USEC_PER_SEC - ref_td))
 			break;
 
 		ref_td = td;
@@ -155,7 +156,7 @@ up_device_battery_estimate_power (UpDeviceBattery *sel
 	 */
 	if (cur->state == UP_DEVICE_STATE_UNKNOWN) {
 		/* Consider a rate of 0.5W as "no change", otherwise set CHARGING/DISCHARGING */
-		if (abs(energy_rate) < 0.5)
+		if (fabs(energy_rate) < 0.5)
 			return;
 		else if (energy_rate < 0.0)
 			cur->state = UP_DEVICE_STATE_DISCHARGING;
