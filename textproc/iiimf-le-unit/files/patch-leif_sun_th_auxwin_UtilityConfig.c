--- leif/sun_le_asia/th_TH/auxwin/UtilityConfig.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/th_TH/auxwin/UtilityConfig.c	Wed Feb 16 20:45:11 2005
@@ -118,7 +118,7 @@
 	lang_name = (char *)get_langname_from_locale(locale_name);
 	DEBUG_printf("lang_name:%s\n", lang_name);
 
-	sprintf(file_name, "/usr/lib/im/locale/%s/%s", lang_name, UTILITY_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/%s", lang_name, UTILITY_FILE_NAME);
 	DEBUG_printf("file_name:%s\n", file_name);
 
 	read_utility_config_file(file_name);
