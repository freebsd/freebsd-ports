--- ui/app_list/app_list_constants.h.orig	2016-03-25 13:05:03 UTC
+++ ui/app_list/app_list_constants.h
@@ -92,8 +92,8 @@ APP_LIST_EXPORT extern const char kSearc
 APP_LIST_EXPORT extern const char kSearchQueryLength[];
 APP_LIST_EXPORT extern const char kSearchResultDistanceFromOrigin[];
 
-#if defined(OS_LINUX)
-// The WM_CLASS name for the app launcher window on Linux.
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
+// The WM_CLASS name for the app launcher window on Linux/FreeBSD.
 APP_LIST_EXPORT extern const char kAppListWMClass[];
 #endif
 
