
$FreeBSD$

--- main/htmlprocessor.h.orig	Sat Jul 17 13:00:47 2004
+++ main/htmlprocessor.h	Sat Jul 17 13:00:53 2004
@@ -49,6 +49,8 @@
 	
 	void setBaseURL(const URI& url);
 	
+	void setUserAgent(const std::string& ua);
+	
 	using HtmlLexer::consumeDataChunk;
 	
 	void consumeEOF();
@@ -305,6 +307,7 @@
 	std::string m_curAttrName;
 	std::string m_closingTagName;
 	URI m_baseURL;
+	std::string m_userAgent;
 	int m_scriptsRule;
 	int m_jsengineRule;
 	int m_targetBlankRule;
