--- leif/sun_le_asia/zh_HK/input_methods/newzy/CikuOper.h	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/zh_HK/input_methods/newzy/CikuOper.h	Wed Feb 16 20:48:43 2005
@@ -64,7 +64,7 @@
 #define SINGLEHZ_DSP_SIMP      1
 #define SINGLEHZ_DSP_FULL      2
 
-#define  CIKU_DATA_PATH     "/usr/lib/im/locale/zh_HK/common/data"
+#define  CIKU_DATA_PATH     (IMDIR "/locale/zh_HK/common/data")
 
 typedef struct _CizuItem {
 	UCHAR     szLine[CIZU_ITEM_LEN];           /* Org Line read from file */
