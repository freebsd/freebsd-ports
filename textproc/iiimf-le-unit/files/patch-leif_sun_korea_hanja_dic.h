--- leif/sun_le_korea/korean/hanja_dic.h	Sat Mar 27 10:46:45 2004
+++ leif/sun_le_korea/korean/hanja_dic.h	Wed Feb 16 20:49:10 2005
@@ -19,9 +19,9 @@
 
 #define USRNAME		".usrhjd"
 #ifdef __STDC__
-#define SYSPATH		"/usr/lib/im/locale/ko_KR/common/data"
+#define SYSPATH		(IMDIR "/locale/ko_KR/common/data")
 #else
-#define SYSPATH		"/usr/lib/im/locale/ko_KR/common/data"
+#define SYSPATH		(IMDIR "/locale/ko_KR/common/data")
 #endif
 #define SYSNAME		"syshjd"
 #define NULNAME		"nulhjd"
