--- leif/sun_le_asia/common/auxwin/LookupImpl.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/common/auxwin/LookupImpl.c	Wed Feb 16 20:44:18 2005
@@ -475,7 +475,7 @@
 	sLocaleName = setlocale(LC_ALL, NULL);
 	lang_name = (char *)get_langname_from_locale(sLocaleName);
 
-	sprintf(path_name, "/usr/lib/im/locale/%s", lang_name);
+	sprintf(path_name, IMDIR "/locale/%s", lang_name);
 	ret = read_keyboard_config_file(path_name, DEFAULT_SYMBOLS_CONFIG_FILE);
 }
 
