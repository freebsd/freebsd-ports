--- src/XMLParser.cpp.orig	Wed Nov  6 14:04:53 2002
+++ src/XMLParser.cpp	Wed Nov  6 14:11:19 2002
@@ -46,7 +46,7 @@
 {
 	if (m_parser)
 	{
-		XML_ParserFree(m_parser);
+		XML_ParserFree((XML_Parser) m_parser);
 		m_parser = 0;
 	}
 }
@@ -56,27 +56,27 @@
 {
 	FreeParser();
 	m_parser = XML_ParserCreateNS(encoding, '#');
-	XML_SetElementHandler(m_parser,
+	XML_SetElementHandler((XML_Parser) m_parser,
 			XMLParser::_startElement,
 			XMLParser::_endElement);
 
-	XML_SetCharacterDataHandler(m_parser,
+	XML_SetCharacterDataHandler((XML_Parser) m_parser,
 			XMLParser::_characterData);
 
-	XML_SetStartNamespaceDeclHandler(m_parser,
+	XML_SetStartNamespaceDeclHandler((XML_Parser) m_parser,
 			XMLParser::_startNamespace);
 
-	XML_SetEndNamespaceDeclHandler(m_parser,
+	XML_SetEndNamespaceDeclHandler((XML_Parser) m_parser,
 			XMLParser::_endNamespace);
 
-	XML_SetUserData(m_parser, this);
+	XML_SetUserData((XML_Parser) m_parser, this);
 }
 
 void *
 XMLParser::GetParseBuffer(int size)
 {
 	if (m_parser)
-		return XML_GetBuffer(m_parser, size);
+		return XML_GetBuffer((XML_Parser) m_parser, size);
 	return 0;
 }
 
@@ -84,7 +84,7 @@
 XMLParser::ParseBuffer(int size)
 {
 	if (m_parser)
-		return XML_ParseBuffer(m_parser, size, size == 0) != 0;
+		return XML_ParseBuffer((XML_Parser) m_parser, size, size == 0) != 0;
 	return false;
 }
 
@@ -92,7 +92,7 @@
 XMLParser::GetErrorMessage()
 {
 	if (m_parser)
-		return XML_ErrorString(XML_GetErrorCode(m_parser));
+		return XML_ErrorString(XML_GetErrorCode((XML_Parser) m_parser));
 	return 0;
 }
