--- ../src/common/cole/oledecod.c~	2008-10-13 05:21:28.000000000 +0200
+++ ../src/common/cole/oledecod.c	2008-10-13 05:21:28.000000000 +0200
@@ -44,7 +44,7 @@
 #if __GNUC__
 	#if __APPLE__
 	#else
-	#include <malloc.h>
+	#include <stdlib.h>
 	#endif
 	#include <sys/types.h>
 #endif 
