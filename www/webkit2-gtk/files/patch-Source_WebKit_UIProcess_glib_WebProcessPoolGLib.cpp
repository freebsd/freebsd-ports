--- Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp.orig	2024-08-29 11:52:43 UTC
+++ Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp
@@ -201,7 +201,7 @@ void WebProcessPool::setSandboxEnabled(bool enabled)
         return;
     }
 
-#if !USE(SYSTEM_MALLOC)
+#if !USE(SYSTEM_MALLOC) && OS(LINUX)
     if (RUNNING_ON_VALGRIND)
         return;
 #endif
