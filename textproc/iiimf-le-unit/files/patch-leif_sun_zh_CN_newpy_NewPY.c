--- leif/sun_le_asia/zh_CN/newpy/NewPY.c	Fri Mar 26 18:13:39 2004
+++ leif/sun_le_asia/zh_CN/newpy/NewPY.c	Wed Feb 16 20:45:45 2005
@@ -126,7 +126,7 @@
 #define  PUNCT_CHINESE      0
 #define  PUNCT_ENGLISH      1
 
-#define  CIKU_DATA_PATH     "/usr/lib/im/locale/zh_CN/common/data"
+#define  CIKU_DATA_PATH     (IMDIR "/locale/zh_CN/common/data")
 
 JINT      nGlobalSpMode;      /* ZRM, CStar, ABC */
 
