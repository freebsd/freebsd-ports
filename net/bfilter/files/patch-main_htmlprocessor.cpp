
$FreeBSD$

--- main/htmlprocessor.cpp.orig	Sat Jul 17 12:59:48 2004
+++ main/htmlprocessor.cpp	Sat Jul 17 13:00:53 2004
@@ -61,6 +61,7 @@
 	m_mapTags(parent.m_mapTags),
 	m_imgTagsUsingMap(parent.m_imgTagsUsingMap),
 	m_baseURL(parent.m_baseURL),
+	m_userAgent(parent.m_userAgent),
 	m_scriptsRule(parent.m_scriptsRule),
 	m_jsengineRule(parent.m_jsengineRule),
 	m_targetBlankRule(parent.m_targetBlankRule),
@@ -84,6 +85,12 @@
 }
 
 void
+HtmlProcessor::setUserAgent(const std::string& ua)
+{
+	m_userAgent = ua;	
+}
+
+void
 HtmlProcessor::consumeEOF()
 {
 	HtmlLexer::consumeEOF();
@@ -113,6 +120,7 @@
 	std::string().swap(m_onload);
 	std::string().swap(m_onunload);
 	//m_baseURL = URI("");
+	//m_userAgent = "";
 	//m_scriptsRule = 0;
 	//m_jsengineRule = 0;
 	//m_targetBlankRule = 0;
@@ -821,7 +829,7 @@
 							"too many redirects ("+StringUtils::fromNumber(i)+")");
 					}
 					HttpRequest request("GET", url);
-					request.headers().setHeader(HttpHeader("User-Agent", "Mozilla/5.0 (Windows; U; Win98; en-US) Netscape6/6.0"));
+					request.headers().setHeader(HttpHeader("User-Agent", m_userAgent));
 					request.headers().setHeader(HttpHeader("Referrer", m_baseURL.toString()));
 					request.headers().setHeader(HttpHeader("Accept", "*" "/" "*"));
 					HttpResponse response = fetcher.request(request);
@@ -1173,11 +1181,13 @@
 	if (node->hasAttribute("onmouseover")) {
 		if (checkCodeForPopups(node->getAttribute("onmouseover"))) {
 			node->setRawAttribute("onmouseover", "/* popup detected by BFilter */");
+			modified = true;
 		}
 	}
 	if (node->hasAttribute("onmouseout")) {
 		if (checkCodeForPopups(node->getAttribute("onmouseout"))) {
 			node->setRawAttribute("onmouseout", "/* popup detected by BFilter */");
+			modified = true;
 		}
 	}
 	return modified;
