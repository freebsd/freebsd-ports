--- leif/sun_le_asia/common/leif/qjbj_punct.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/common/leif/qjbj_punct.c	Wed Feb 16 20:44:53 2005
@@ -384,7 +384,7 @@
 
 	lang_name = (char *)get_langname_from_langid(lang_id);
 	DEBUG_printf("lang_name:%s\n", lang_name);
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/%s", lang_name, QJBJ_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/common/%s", lang_name, QJBJ_FILE_NAME);
 	DEBUG_printf("file_name:%s\n", file_name);
 
 	fd = fopen(file_name, "r");
@@ -441,7 +441,7 @@
 	PunctCharListByLang[lang_id].bInit = 1;
 
 	lang_name = (char *)get_langname_from_langid(lang_id);
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/%s", lang_name, PUNCT_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/common/%s", lang_name, PUNCT_FILE_NAME);
 	DEBUG_printf("file_name:%s\n", file_name);
 
 	fd = fopen(file_name, "r");
