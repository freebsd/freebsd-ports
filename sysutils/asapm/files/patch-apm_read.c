--- apm_read.c.orig	Wed Jul 27 08:23:06 2005
+++ apm_read.c	Wed Jul 27 23:15:33 2005
@@ -413,6 +413,9 @@
 	unsigned int remaining_capacity = 0;
 	unsigned int present_rate = 0;
 
+	unsigned int percent;
+	unsigned int time_left;
+
 	if ( ! acpi_available )
 		return -1;
 
@@ -617,7 +620,7 @@
 	 * Calculate the percentage and time to full charge
 	 * or discharge based on the reported rate.
 	 */
-	unsigned int percent = 
+	percent = 
 		last_full_capacity ?
 		(float)remaining_capacity / (float)last_full_capacity * 100
 		: 0;
@@ -626,7 +629,6 @@
 		++state.update;
 	}
 
-	unsigned int time_left;
 	if ( state.battery_status == BATTERY_CHARGING ) {
 		time_left = 
 			present_rate ?
