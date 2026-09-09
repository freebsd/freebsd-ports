--- Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp.orig	2024-10-21 09:00:02 UTC
+++ Source/WebKit/UIProcess/glib/WebProcessPoolGLib.cpp
@@ -207,7 +207,7 @@ void WebProcessPool::setSandboxEnabled(bool enabled)
         return;
     }
 
-#if !USE(SYSTEM_MALLOC)
+#if !USE(SYSTEM_MALLOC) && OS(LINUX)
     if (RUNNING_ON_VALGRIND)
         return;
 #endif
