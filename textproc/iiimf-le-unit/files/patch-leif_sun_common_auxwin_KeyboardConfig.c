--- leif/sun_le_asia/common/auxwin/KeyboardConfig.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/common/auxwin/KeyboardConfig.c	Wed Feb 16 20:44:10 2005
@@ -145,7 +145,7 @@
 zh_CN.GBK/keyboard_layout2.txt
 common/keyboard_layout.txt
 
-base directory:  /usr/lib/im/locale/<locale>/
+base directory:  /usr/local/lib/im/locale/<locale>/
 
 */
 int read_keyboard_config_file(char *path_name, char *file_name)
@@ -557,7 +557,7 @@
 	nLocaleID = get_encodeid_from_locale(sLocaleName);
 
 	lang_name = (char *)get_langname_from_locale(sLocaleName);
-	sprintf(path_name, "/usr/lib/im/locale/%s", lang_name);
+	sprintf(path_name, IMDIR "/locale/%s", lang_name);
 
 	DEBUG_printf("path_name:%s\n", path_name);
 
