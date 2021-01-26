--- Source/WebCore/xml/XPathGrammar.y.orig	2020-03-04 17:16:37 UTC
+++ Source/WebCore/xml/XPathGrammar.y
@@ -47,7 +47,7 @@ using namespace XPath;
 
 %}
 
-%pure-parser
+%define api.pure
 %lex-param { parser }
 %parse-param { Parser& parser }
 
