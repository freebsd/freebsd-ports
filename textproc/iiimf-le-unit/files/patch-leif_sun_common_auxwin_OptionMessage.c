--- leif/sun_le_asia/common/auxwin/OptionMessage.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/common/auxwin/OptionMessage.c	Wed Feb 16 20:44:22 2005
@@ -127,7 +127,7 @@
 
 	nLocaleID = get_encodeid_from_locale(locale_name);
 	lang_name = get_langname_from_locale(locale_name);
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/%s", lang_name, MSG_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/common/%s", lang_name, MSG_FILE_NAME);
 	gCatd = catopen(file_name, 0);
 	if (gCatd == (nl_catd)-1)
 		printf("WARNING: Could not open message catalog: %s\n", name);
