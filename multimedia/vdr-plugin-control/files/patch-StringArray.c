--- a/StringArray.c
+++ b/StringArray.c
@@ -11,7 +11,11 @@
 #endif // _GNU_SOURCE
 
 
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <stdio.h>
 
