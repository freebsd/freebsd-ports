--- leif/sun_le_asia/common/include/hzinput.h	Fri May 28 16:52:29 2004
+++ leif/sun_le_asia/common/include/hzinput.h	Wed Feb 16 20:48:38 2005
@@ -63,7 +63,7 @@
 #define ENGINE_NOT_INITIATED 		2
 #define ENGINE_INITIATED     		3
 
-#define DEFAULT_ENGINE_PATH		"/usr/lib/im/locale"
+#define DEFAULT_ENGINE_PATH		(IMDIR "/locale")
 #define DEFAULT_DICT_PATH		"data"
 #define COMMON_ENGINE_PATH		"common"
 #define CODETABLE_ENGINE_NAME    	"ctim"
