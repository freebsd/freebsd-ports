--- native/CefApp.cpp.orig	2026-09-08 14:07:06 UTC
+++ native/CefApp.cpp
@@ -15,7 +15,7 @@
 #include "scheme_handler_factory.h"
 #include "util.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include <X11/Xlib.h>
 #endif
 
@@ -91,7 +91,7 @@ Java_org_cef_CefApp_N_1Startup(JNIEnv* env,
 Java_org_cef_CefApp_N_1Startup(JNIEnv* env,
                                jclass,
                                jstring pathToCefFramework) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
   XInitThreads();
 #elif defined(OS_MACOSX)
   // Can't use GetJNIString before the CEF library is loaded.
