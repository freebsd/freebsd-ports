--- leif/sun_le_asia/zh_TW/input_methods/dayi/dayi_im.c	Thu May 13 19:23:13 2004
+++ leif/sun_le_asia/zh_TW/input_methods/dayi/dayi_im.c	Wed Feb 16 20:46:21 2005
@@ -154,7 +154,7 @@
 	if (pDayiData == NULL)
 		return(-1);
 
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/dayi.cfg", core->envinfo.lang_name);
+	sprintf(file_name, IMDIR "/locale/%s/common/dayi.cfg", core->envinfo.lang_name);
 	ret = DayiData_Init(file_name, pDayiData);
 	if (ret == DAYI_ERROR) {
 		DayiData_Free(pDayiData);
