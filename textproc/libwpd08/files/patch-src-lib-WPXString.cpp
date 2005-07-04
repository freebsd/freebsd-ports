--- src/lib/WPXString.cpp.orig	Tue Jun 28 00:17:50 2005
+++ src/lib/WPXString.cpp	Tue Jun 28 00:15:50 2005
@@ -179,7 +179,7 @@
 
 void WPXString::clear()
 {
-	static_cast<std::string *>(m_buf)->clear();
+	static_cast<std::string *>(m_buf)->erase(static_cast<std::string *>(m_buf)->begin(), static_cast<std::string *>(m_buf)->end());
 }
 
 int WPXString::len() const
