--- libenv/sysinfo.h.orig	2025-11-17 06:20:41.000000000 -0800
+++ libenv/sysinfo.h	2025-11-17 07:23:36.850520000 -0800
@@ -42,4 +42,5 @@
 JsonElement* GetUserInfo(const void *passwd);
 JsonElement* GetGroupInfo(const void *group);
 
+#include <pcre.h>
 #endif
