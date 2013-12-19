--- src/lib/server/CConfig.cpp.orig	2011-01-21 11:51:35.000000000 +0800
+++ src/lib/server/CConfig.cpp	2013-11-26 10:00:44.000000000 +0800
@@ -1908,9 +1908,9 @@
 	return m_line;
 }
 
-CConfigReadContext::operator void*() const
+CConfigReadContext::operator bool() const
 {
-	return m_stream;
+	return m_stream.good();
 }
 
 bool
