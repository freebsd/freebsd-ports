--- src/devices.c.orig	Fri Mar 24 20:07:57 2006
+++ src/devices.c	Fri Mar 24 20:11:24 2006
@@ -373,9 +373,9 @@
 	gchar* buffer = NULL;
     exec_run_cmd(command, &buffer);
 	if(buffer == NULL)
-		g_critical("devices_probe_bus - Failed to scan the scsi bus");
+		g_warning("devices_probe_bus - Failed to scan the scsi bus");
 	else if(!devices_parse_cdrecord_output(buffer, bus))
-		g_critical("devices_probe_bus - failed to parse cdrecord output");
+		g_warning("devices_probe_bus - failed to parse cdrecord output");
 	else
 		ok = TRUE;	
 	g_free(buffer);
@@ -404,7 +404,7 @@
 	}
 	else
 	{
-		g_critical("Failed to open %s", file);
+		g_warning("Failed to open %s", file);
 	}
 	g_free(file);
 }
@@ -423,11 +423,11 @@
 	gchar **device_strs = NULL, **devices = NULL;	
 	if((devices = gbcommon_get_file_as_list("/proc/scsi/sg/devices")) == NULL)
 	{
-		g_critical("Failed to open /proc/scsi/sg/devices");
+		g_warning("Failed to open /proc/scsi/sg/devices");
 	}
 	else if((device_strs = gbcommon_get_file_as_list("/proc/scsi/sg/device_strs")) == NULL)
 	{
-		g_critical("Failed to open /proc/scsi/sg/device_strs");
+		g_warning("Failed to open /proc/scsi/sg/device_strs");
 	}
 	else
 	{
@@ -443,7 +443,7 @@
 				if(sscanf(*device, "%d\t%*d\t%d\t%d\t%d", 
 					&scsihost, &scsiid, &scsilun, &scsitype) != 4)
 				{
-					g_critical("Error reading scsi information from /proc/scsi/sg/devices");
+					g_warning("Error reading scsi information from /proc/scsi/sg/devices");
 				}			
 				/* 5 is the magic number according to lib-nautilus-burn */
 				else if(scsitype == 5)
@@ -560,7 +560,7 @@
 	gchar **info = NULL;
 	if((info = gbcommon_get_file_as_list("/proc/sys/dev/cdrom/info")) == NULL)
 	{
-		g_critical("Failed to open /proc/sys/dev/cdrom/info");
+		g_warning("Failed to open /proc/sys/dev/cdrom/info");
 	}
 	else
 	{
@@ -686,7 +686,7 @@
     g_free(device);
 	if(cdrom < 0)
 	{
-        g_critical("Error opening device %s",device);
+        g_warning("Error opening device %s",device);
    	}
     else
     {			
@@ -695,10 +695,10 @@
         if(ioctl(cdrom, CDIOCEJECT, 0) < 0)
             ret = TRUE;
         else 
-            g_critical("devices_eject_disk - ioctl failed");
+            g_warning("devices_eject_disk - ioctl failed");
 #else        
         if(ioctl(cdrom, CDROMEJECT, 0) < 0)
-            g_critical("devices_eject_disk - ioctl failed");
+            g_warning("devices_eject_disk - ioctl failed");
         else
             ret = TRUE;
 #endif                
@@ -723,9 +723,9 @@
 	
 	GString* buffer = exec_run_cmd(command);
 	if(buffer == NULL)
-		g_critical("devices_get_max_speed_for_drive - Failed to scan the scsi bus");
+		g_warning("devices_get_max_speed_for_drive - Failed to scan the scsi bus");
 	else if(!devices_parse_cdrecord_output(buffer->str, bus))	
-		g_critical("devices_get_max_speed_for_drive - failed to parse cdrecord output");
+		g_warning("devices_get_max_speed_for_drive - failed to parse cdrecord output");
 	else
 		ok = TRUE;
 	
@@ -749,7 +749,7 @@
     close(fd);
     if (ret == -1)
 	{
-		g_critical("devices_is_disk_inserted - ioctl failed");
+		g_warning("devices_is_disk_inserted - ioctl failed");
     }
     else 
     {
