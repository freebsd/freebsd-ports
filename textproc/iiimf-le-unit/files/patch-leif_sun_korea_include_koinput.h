--- leif/sun_le_korea/include/koinput.h	Fri Apr 23 15:40:46 2004
+++ leif/sun_le_korea/include/koinput.h	Wed Feb 16 20:48:57 2005
@@ -76,7 +76,7 @@
 #define ENGINE_NOT_INITIATED 		2
 #define ENGINE_INITIATED     		3
 
-#define DEFAULT_ENGINE_PATH		"/usr/lib/im/locale"
+#define DEFAULT_ENGINE_PATH		(IMDIR "/locale")
 #define DEFAULT_DICT_PATH		"data"
 #define COMMON_ENGINE_PATH		"common"
 #define LANGNAME                        "ko_KR"
