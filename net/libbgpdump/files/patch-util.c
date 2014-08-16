--- util.c.orig	2014-08-15 12:58:56.000000000 -0700
+++ util.c	2014-08-15 13:01:14.000000000 -0700
@@ -29,6 +29,7 @@
 #include <syslog.h>
 #include <time.h>
 #include <string.h>
+#include <inttypes.h>
 
 static bool use_syslog = true;
 
@@ -110,17 +111,7 @@
 
 int int2str(uint32_t value, char* str)
 {
-    const int LEN = 11;
-    char b[LEN];
-    int i = LEN;
-    b[i--] = '\0';
-    
-    do {
-        b[i--] = (char)(48 + (value % 10));
-    } while (value /= 10);
-
-    memcpy(str, b + i + 1, LEN - i);
-    return LEN - i - 1;
+  return snprintf(str, 11, "%"PRIu32, value);
 }
 
 static void ti2s(uint32_t value) {
