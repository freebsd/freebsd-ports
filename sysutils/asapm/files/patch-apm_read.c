--- apm_read.c.orig	Tue May 17 06:49:13 2005
+++ apm_read.c	Sun May 29 20:38:24 2005
@@ -301,6 +301,9 @@
 	unsigned int remaining_capacity = 0;
 	unsigned int present_rate = 0;
 
+	unsigned int percent;
+	unsigned int time_left;
+
         /* First check if there is an ACPI system */
         if ((fd = open("/proc/acpi/info", O_RDONLY)) == -1) {
                 error_handle(1, "open_acpi_info_file");
@@ -503,7 +506,7 @@
 	 * Calculate the percentage and time to full charge
 	 * or discharge based on the reported rate.
 	 */
-	unsigned int percent = 
+	percent = 
 		last_full_capacity ?
 		(float)remaining_capacity / (float)last_full_capacity * 100
 		: 0;
@@ -512,7 +515,6 @@
 		++state.update;
 	}
 
-	unsigned int time_left;
 	if ( state.battery_status == BATTERY_CHARGING ) {
 		time_left = 
 			present_rate ?
