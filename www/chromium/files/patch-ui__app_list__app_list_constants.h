--- ui/app_list/app_list_constants.h.orig	2014-10-02 17:39:48 UTC
+++ ui/app_list/app_list_constants.h
@@ -66,8 +66,8 @@
 
 APP_LIST_EXPORT extern const ui::ResourceBundle::FontStyle kItemTextFontStyle;
 
-#if defined(OS_LINUX)
-// The WM_CLASS name for the app launcher window on Linux.
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
+// The WM_CLASS name for the app launcher window on Linux/FreeBSD.
 APP_LIST_EXPORT extern const char kAppListWMClass[];
 #endif
 
