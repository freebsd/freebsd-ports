--- src/openseachest_util_options.c.orig	2021-05-21 17:50:44 UTC
+++ src/openseachest_util_options.c
@@ -108,12 +108,12 @@ void print_Elevated_Privileges_Text()
 
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
 
@@ -147,7 +147,7 @@ void openseachest_utility_Info(const char *utilityName
     printf(" %s Version: %s-%s ", utilityName, buildVersion, seaCPublicVersion);
     print_Architecture(architecture);
     printf("\n");
-    printf(" Build Date: %s\n", __DATE__);
+    printf(" Build Date: %s\n", "Jan 19 2038");
     if (0 == strftime(currentTime, 30, "%c", get_Localtime(&g_curTime, &utilTime)))
     {
         sprintf(currentTime, "Unable to get local time");
@@ -174,7 +174,7 @@ void utility_Full_Version_Info(const char *utilityName
     printf("\topensea-common Version: %s\n", openseaCommonVersion);
     printf("\topensea-transport Version: %" PRId32".%" PRId32".%" PRId32"\n", seaCPublicMajorVersion, seaCPublicMinorVersion, seaCPublicPatchVersion);
     printf("\topensea-operations Version: %s\n", openseaOperationVersion);
-    printf("\tBuild Date: %s\n", __DATE__);
+    printf("\tBuild Date: %s\n", "Jan 19 2038");
     printf("\tCompiled Architecture: ");
     print_Architecture(get_Compiled_Architecture());
     printf("\n\tDetected Endianness: ");
