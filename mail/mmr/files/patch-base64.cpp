--- base64.cpp.orig	Mon Oct 21 23:29:39 2002
+++ base64.cpp	Mon Oct 21 23:29:56 2002
@@ -1,3 +1,4 @@
+#include <string.h>
 
 /* Convert to Base64 encoding */
 static char to_base64[64] = {
