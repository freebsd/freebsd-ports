--- leif/sun_le_korea/include/le-options.h	Tue Apr 20 08:53:49 2004
+++ leif/sun_le_korea/include/le-options.h	Wed Feb 16 20:49:02 2005
@@ -29,7 +29,7 @@
 #define Bool Boolean
 #endif
 
-#define DEFAULT_KOLE_OPTION_FILE "/usr/lib/im/locale/ko_KR/kole.conf"
+#define DEFAULT_KOLE_OPTION_FILE (IMDIR "/locale/ko_KR/kole.conf")
 /* NAME of Options */
 #define STR_OPTION_CHARSET "charset"
 #define STR_OPTION_DELETION "delete by jaso"
