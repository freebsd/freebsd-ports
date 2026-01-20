--- bozohttpd.h.orig	2024-02-04 05:55:04 UTC
+++ bozohttpd.h
@@ -44,8 +44,8 @@
 #include <lua.h>
 #endif
 
-#ifndef NO_BLOCKLIST_SUPPORT
-#include <blocklist.h>
+#ifndef NO_BLACKLIST_SUPPORT
+#include <blacklist.h>
 void pfilter_notify(const int, const int);
 #endif
 
