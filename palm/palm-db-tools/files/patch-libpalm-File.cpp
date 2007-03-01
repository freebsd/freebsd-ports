--- libpalm/File.cpp.orig	Thu Jun 19 16:37:47 2003
+++ libpalm/File.cpp
@@ -270,7 +270,7 @@
     }
 
     if (m_sort_info.raw_size() > 0) {
-        f.write((char *) m_sort_info.raw_size(), m_sort_info.raw_size());
+        f.write((char *) m_sort_info.raw_data(), m_sort_info.raw_size());
         if (!f)
             throw PalmLib::error("unable to write sort info block");
     }
