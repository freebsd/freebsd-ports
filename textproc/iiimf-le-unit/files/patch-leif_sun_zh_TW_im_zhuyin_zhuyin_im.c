--- leif/sun_le_asia/zh_TW/input_methods/zhuyin/zhuyin_im.c	Thu May 13 19:23:13 2004
+++ leif/sun_le_asia/zh_TW/input_methods/zhuyin/zhuyin_im.c	Wed Feb 16 20:46:35 2005
@@ -155,7 +155,7 @@
 	if (pZhuyinData == NULL)
 		return(-1);
 
-	sprintf(file_name, "/usr/lib/im/locale/%s/common/zhuyin.cfg", core->envinfo.lang_name);
+	sprintf(file_name, IMDIR "/locale/%s/common/zhuyin.cfg", core->envinfo.lang_name);
 	ret = ZhuyinData_Init(file_name, pZhuyinData);
 	if (ret == ZHUYIN_ERROR) {
 		ZhuyinData_Free(pZhuyinData);
