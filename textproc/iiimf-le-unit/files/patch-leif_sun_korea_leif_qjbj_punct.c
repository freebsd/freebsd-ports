--- leif/sun_le_korea/leif/qjbj_punct.c	Sat Mar 27 10:46:45 2004
+++ leif/sun_le_korea/leif/qjbj_punct.c	Wed Feb 16 20:47:08 2005
@@ -350,7 +350,7 @@
 
 	lang_name = (char *)get_langname_from_langid(lang_id);
 	logf("lang_name:%s\n", lang_name);
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/%s", lang_name, QJBJ_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/common/%s", lang_name, QJBJ_FILE_NAME);
 	logf("file_name:%s\n", file_name);
 
 	fd = fopen(file_name, "r");
@@ -407,7 +407,7 @@
 	PunctCharListByLang[lang_id].bInit = 1;
 
 	lang_name = (char *)get_langname_from_langid(lang_id);
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/%s", lang_name, PUNCT_FILE_NAME);
+	sprintf(file_name, IMDIR "/locale/%s/common/%s", lang_name, PUNCT_FILE_NAME);
 	logf("file_name:%s\n", file_name);
 
 	fd = fopen(file_name, "r");
