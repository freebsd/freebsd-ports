--- kplayer/kplayersettings.h.orig	Sat Oct 16 02:00:48 2004
+++ kplayer/kplayersettings.h	Sat Oct 16 02:01:22 2004
@@ -982,7 +982,7 @@
   }
 
   QString executablePathDefault (void) const
-    { return m_executable_path_default.isEmpty() ? "mplayer" : m_executable_path_default; }
+    { return m_executable_path_default.isEmpty() ? QString::fromLatin1("mplayer") : m_executable_path_default; }
   void setExecutablePathDefault (QString path)
     { m_executable_path_default = path; }
 
