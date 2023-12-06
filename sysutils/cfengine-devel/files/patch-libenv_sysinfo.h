--- libenv/sysinfo.h.orig	2023-12-04 08:49:45.000000000 -0800
+++ libenv/sysinfo.h	2023-12-05 21:21:51.352396000 -0800
@@ -40,4 +40,5 @@
 
 JsonElement* GetUserInfo(const void *passwd);
 
+#include <pcre.h>
 #endif
