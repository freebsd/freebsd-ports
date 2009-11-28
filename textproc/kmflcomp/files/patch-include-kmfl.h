--- include/kmfl.h	2006-11-03 10:32:24.000000000 -0800
+++ include/kmfl.h	2009-11-18 16:57:02.000000000 -0800
@@ -31,6 +31,7 @@
 #endif
 
 
+#include <sys/types.h>
 #define FILE_VERSION	"1"
 #define BASE_VERSION	"320"
 #define LAST_VERSION	"600"
@@ -79,25 +80,12 @@
 #ifdef _WIN32
 	typedef unsigned int UINT; 	// 32-bit unsigned integer (general purpose)
 #else
-#include <stdint.h>
-#ifdef __uint32_t_defined
-	typedef uint32_t UINT;
-#else
-	typedef unsigned long UINT;	// 32-bit unsigned integer (general purpose)
-#endif
+	typedef u_int32_t UINT;
 #endif
 
-#ifdef __int32_t_defined
-	typedef int32_t INT;
-#else
-	typedef long INT;	// 32-bit unsigned integer (general purpose)
-#endif
+typedef int32_t INT;
 
-#ifdef __uint8_t_defined
-typedef uint8_t BYTE;
-#else
-typedef unsigned char BYTE; 	// 8-bit unsigned integer
-#endif
+typedef u_int8_t BYTE;
 typedef UINT ITEM; 	// 32-bit unsigned integer for UTF-32 or control values
 typedef UINT OFFSET;	// 32-bit unsigned integer used as table offsets
 
