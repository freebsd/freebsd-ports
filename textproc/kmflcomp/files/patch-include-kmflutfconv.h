--- include/kmflutfconv.h	2006-03-10 15:34:49.000000000 -0800
+++ include/kmflutfconv.h	2009-11-18 16:56:36.000000000 -0800
@@ -26,16 +26,10 @@
 extern "C" {
 #endif
 
-
-#ifdef __uint32_t_defined
-typedef uint32_t        UTF32;
-typedef uint16_t        UTF16;
-typedef uint8_t UTF8;
-#else
-typedef unsigned long   UTF32;
-typedef unsigned short  UTF16;
-typedef unsigned char   UTF8;
-#endif
+#include <sys/types.h>
+typedef u_int32_t        UTF32;
+typedef u_int16_t        UTF16;
+typedef u_int8_t UTF8;
 
 size_t IConvertUTF8toUTF16 (
 		const UTF8** sourceStart, const UTF8* sourceEnd, 

