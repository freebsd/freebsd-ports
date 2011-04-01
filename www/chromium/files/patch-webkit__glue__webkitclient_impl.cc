--- webkit/glue/webkitclient_impl.cc.orig	2011-02-03 10:01:07.000000000 +0100
+++ webkit/glue/webkitclient_impl.cc	2011-02-05 00:07:18.000000000 +0100
@@ -42,7 +42,7 @@
 #include "webkit/glue/websocketstreamhandle_impl.h"
 #include "webkit/glue/weburlloader_impl.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "v8/include/v8.h"
 #endif
 
@@ -205,7 +205,7 @@
 }
 
 WebThemeEngine* WebKitClientImpl::themeEngine() {
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_WIN) || defined(OS_POSIX)
   return &theme_engine_;
 #else
   return NULL;
