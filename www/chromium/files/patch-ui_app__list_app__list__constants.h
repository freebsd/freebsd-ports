--- ui/app_list/app_list_constants.h.orig	2017-01-26 00:49:31 UTC
+++ ui/app_list/app_list_constants.h
@@ -89,8 +89,8 @@ APP_LIST_EXPORT extern const char kSearc
 APP_LIST_EXPORT extern const char kSearchQueryLength[];
 APP_LIST_EXPORT extern const char kSearchResultDistanceFromOrigin[];
 
-#if defined(OS_LINUX)
-// The WM_CLASS name for the app launcher window on Linux.
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
+// The WM_CLASS name for the app launcher window on Linux/FreeBSD.
 APP_LIST_EXPORT extern const char kAppListWMClass[];
 #endif
 
