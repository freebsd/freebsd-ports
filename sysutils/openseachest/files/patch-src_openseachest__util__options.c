--- src/openseachest_util_options.c.orig	2023-04-12 16:13:25 UTC
+++ src/openseachest_util_options.c
@@ -112,12 +112,12 @@ void print_Elevated_Privileges_Text(void)
 
 char* get_current_year(char *temp_year)
 {
-    size_t len = strlen(__DATE__);
+    size_t len = strlen("Jan 19 2038");
     temp_year[4] = '\0';
-    temp_year[3] = __DATE__[len - 1];
-    temp_year[2] = __DATE__[len - 2];
-    temp_year[1] = __DATE__[len - 3];
-    temp_year[0] = __DATE__[len - 4];
+    temp_year[3] = "Jan 19 2038"[len - 1];
+    temp_year[2] = "Jan 19 2038"[len - 2];
+    temp_year[1] = "Jan 19 2038"[len - 3];
+    temp_year[0] = "Jan 19 2038"[len - 4];
     return temp_year;
 }
 
@@ -151,7 +151,7 @@ void openseachest_utility_Info(const char *utilityName
     printf(" %s Version: %s-%s ", utilityName, buildVersion, seaCPublicVersion);
     print_Architecture(architecture);
     printf("\n");
-    printf(" Build Date: %s\n", __DATE__);
+    printf(" Build Date: %s\n", "Jan 19 2038");
     if (0 == strftime(currentTime, CURRENT_TIME_STRING_MAX_LENGTH, "%c", get_Localtime(&g_curTime, &utilTime)))
     {
         snprintf(currentTime, CURRENT_TIME_STRING_MAX_LENGTH, "Unable to get local time");
@@ -178,7 +178,7 @@ void utility_Full_Version_Info(const char *utilityName
     printf("\topensea-common Version: %s\n", openseaCommonVersion);
     printf("\topensea-transport Version: %" PRId32".%" PRId32".%" PRId32"\n", seaCPublicMajorVersion, seaCPublicMinorVersion, seaCPublicPatchVersion);
     printf("\topensea-operations Version: %s\n", openseaOperationVersion);
-    printf("\tBuild Date: %s\n", __DATE__);
+    printf("\tBuild Date: %s\n", "Jan 19 2038");
     printf("\tCompiled Architecture: ");
     print_Architecture(get_Compiled_Architecture());
     printf("\n\tDetected Endianness: ");
@@ -227,58 +227,58 @@ void print_SeaChest_Util_Exit_Codes(int numberOfToolSp
 
 void get_Scan_Flags(deviceScanFlags *scanFlags, char *optarg)
 {
-    if(strncmp("ata", optarg, strlen(optarg)) == 0)                 
-    {                                                                                                   
-        scanFlags->scanATA = true;                                                                      
-    }                                                                                                   
-    else if (strlen(optarg) == 3 && strncmp("usb", optarg, strlen(optarg)) == 0)            
-    {                                                                                                   
-        scanFlags->scanUSB = true;                                                                      
-    }                                                                                                   
-    else if (strlen(optarg) == 4 && strncmp("scsi", optarg, strlen(optarg)) == 0)           
-    {                                                                                                   
-        scanFlags->scanSCSI = true;                                                                     
-    }                                                                                                   
-    else if (strlen(optarg) == 4 && strncmp("nvme", optarg, strlen(optarg)) == 0)           
-    {                                                                                                   
-        scanFlags->scanNVMe = true;                                                                     
-    }                                                                                                   
-    else if (strlen(optarg) == 4 && strncmp("raid", optarg, strlen(optarg)) == 0)           
-    {                                                                                                   
-        scanFlags->scanRAID = true;                                                                     
-    }                                                                                                   
-    else if (strlen(optarg) == 12 && strncmp("interfaceATA", optarg, strlen(optarg)) == 0)  
-    {                                                                                                   
-        scanFlags->scanInterfaceATA = true;                                                             
-    }                                                                                                   
-    else if (strlen(optarg) == 12 && strncmp("interfaceUSB", optarg, strlen(optarg)) == 0)  
-    {                                                                                                   
-        scanFlags->scanInterfaceUSB = true;                                                             
-    }                                                                                                   
-    else if (strlen(optarg) == 13 && strncmp("interfaceSCSI", optarg, strlen(optarg)) == 0) 
-    {                                                                                                   
-        scanFlags->scanInterfaceSCSI = true;                                                            
-    }                                                                                                   
-    else if (strlen(optarg) == 13 && strncmp("interfaceNVME", optarg, strlen(optarg)) == 0) 
-    {                                                                                                   
-        scanFlags->scanInterfaceNVMe = true;                                                            
-    }                                                                                                   
-    else if (strlen(optarg) == 2 && strncmp("sd", optarg, strlen(optarg)) == 0)             
-    {                                                                                                   
-        scanFlags->scanSD = true;                                                                       
-    }                                                                                                   
-    else if (strlen(optarg) == 6 && strncmp("sgtosd", optarg, strlen(optarg)) == 0)         
-    {                                                                                                   
-        scanFlags->scanSDandSG = true;                                                                  
-    }                                                                                                   
-    else if (strlen(optarg) == 10 && strncmp("ignoreCSMI", optarg, strlen(optarg)) == 0)    
-    {                                                                                                   
-        scanFlags->scanIgnoreCSMI = true;                                                                          
-    }                                                                                                   
-    else if (strlen(optarg) == 15 && strncmp("allowDuplicates", optarg, strlen(optarg)) == 0) 
-    {                                                                                                   
-        scanFlags->scanAllowDuplicateDevices = true;                                                               
-    }              
+    if(strncmp("ata", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanATA = true;
+    }
+    else if (strlen(optarg) == 3 && strncmp("usb", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanUSB = true;
+    }
+    else if (strlen(optarg) == 4 && strncmp("scsi", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanSCSI = true;
+    }
+    else if (strlen(optarg) == 4 && strncmp("nvme", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanNVMe = true;
+    }
+    else if (strlen(optarg) == 4 && strncmp("raid", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanRAID = true;
+    }
+    else if (strlen(optarg) == 12 && strncmp("interfaceATA", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanInterfaceATA = true;
+    }
+    else if (strlen(optarg) == 12 && strncmp("interfaceUSB", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanInterfaceUSB = true;
+    }
+    else if (strlen(optarg) == 13 && strncmp("interfaceSCSI", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanInterfaceSCSI = true;
+    }
+    else if (strlen(optarg) == 13 && strncmp("interfaceNVME", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanInterfaceNVMe = true;
+    }
+    else if (strlen(optarg) == 2 && strncmp("sd", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanSD = true;
+    }
+    else if (strlen(optarg) == 6 && strncmp("sgtosd", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanSDandSG = true;
+    }
+    else if (strlen(optarg) == 10 && strncmp("ignoreCSMI", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanIgnoreCSMI = true;
+    }
+    else if (strlen(optarg) == 15 && strncmp("allowDuplicates", optarg, strlen(optarg)) == 0)
+    {
+        scanFlags->scanAllowDuplicateDevices = true;
+    }
     return;
 }
 
@@ -4310,4 +4310,3 @@ void print_Persistent_Reservations_Preempt_Abort_Help(
         printf("\t\t--%s option in order to specify the key to preempt.\n\n", PERSISTENT_RESERVATION_PREEMPT_LONG_OPT_STRING);
     }
 }
-
