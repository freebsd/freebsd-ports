
$FreeBSD$

--- main/serverresponsestream.cpp.orig	Sat Jul 17 12:34:53 2004
+++ main/serverresponsestream.cpp	Sat Jul 17 12:37:13 2004
@@ -291,9 +291,14 @@
 AbstractResponseFilter*
 ServerResponseStream::tryHtmlFilter(HttpResponseMetadata* metadata)
 {
-	m_pOwner->htmlProcessor()->setBaseURL(m_ptrActiveRequest->getOrigMetadata().requestLine().getURI());
+	m_pOwner->htmlProcessor()->setBaseURL(
+		m_ptrActiveRequest->getOrigMetadata().requestLine().getURI()
+	);
+	m_pOwner->htmlProcessor()->setUserAgent(
+		m_ptrActiveRequest->getOrigMetadata().headers().getHeader("User-Agent").getValue()	);
 	return HtmlResponseFilter::create(
-		m_ptrFilterChain->getNextFilterProvider(), metadata, m_pOwner->htmlProcessor());
+		m_ptrFilterChain->getNextFilterProvider(), metadata, m_pOwner->htmlProcessor()
+	);
 }
 
 AbstractResponseFilter*
