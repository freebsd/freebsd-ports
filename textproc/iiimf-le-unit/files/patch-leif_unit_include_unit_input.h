--- leif/unit/include/unit_input.h	Tue Oct 12 17:24:13 2004
+++ leif/unit/include/unit_input.h	Wed Feb 16 20:49:15 2005
@@ -109,7 +109,7 @@
 #define ENGINE_NOT_INITIATED 		2
 #define ENGINE_INITIATED     		3
 
-#define DEFAULT_ENGINE_PATH		"/usr/lib/im/locale"
+#define DEFAULT_ENGINE_PATH		(IMDIR "/locale")
 #define DEFAULT_DICT_PATH		"data"
 #define COMMON_ENGINE_PATH		"common"
 #define GENERIC_IM_TABLE_NAME    "GENERIC_IM_TABLE"
