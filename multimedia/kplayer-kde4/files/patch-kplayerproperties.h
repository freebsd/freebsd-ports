--- kplayer/kplayerproperties.h.orig	Sat Oct 16 01:58:03 2004
+++ kplayer/kplayerproperties.h	Sat Oct 16 01:58:43 2004
@@ -349,7 +349,7 @@
   // Advanced properties
 
   QString executablePathValue (void) const
-    { return m_executable_path.isEmpty() ? "mplayer" : m_executable_path; }
+    { return m_executable_path.isEmpty() ? QString::fromLatin1("mplayer") : m_executable_path; }
   void setExecutablePathValue (QString path)
     { m_executable_path = path; }
 
