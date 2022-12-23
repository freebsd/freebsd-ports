--- xbmc/windowing/X11/WinSystemX11.cpp.orig	2022-12-21 00:19:40 UTC
+++ xbmc/windowing/X11/WinSystemX11.cpp
@@ -1038,7 +1038,10 @@ bool CWinSystemX11::HasWindowManager()
 
   if(status == Success && items_read)
   {
-    CLog::Log(LOGDEBUG,"Window Manager Name: %s", data);
+    const char* s;
+
+    s = reinterpret_cast<const char*>(data);
+    CLog::Log(LOGDEBUG,"Window Manager Name: {}", s);
   }
   else
     CLog::Log(LOGDEBUG,"Window Manager Name: ");
