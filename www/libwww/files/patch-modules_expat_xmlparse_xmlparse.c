# CVE-2009-3560

--- modules/expat/xmlparse/xmlparse.c.orig	2000-08-28 08:52:01 UTC
+++ modules/expat/xmlparse/xmlparse.c
@@ -2199,6 +2199,9 @@ doProlog(XML_Parser parser,
 	return XML_ERROR_UNCLOSED_TOKEN;
       case XML_TOK_PARTIAL_CHAR:
 	return XML_ERROR_PARTIAL_CHAR;
+      case -XML_TOK_PROLOG_S:
+	tok = -tok;
+	break;
       case XML_TOK_NONE:
 #ifdef XML_DTD
 	if (enc != encoding)
