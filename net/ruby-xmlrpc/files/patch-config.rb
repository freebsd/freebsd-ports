--- lib/config.rb.orig	Tue Jun 18 03:56:29 2002
+++ lib/config.rb	Thu Oct 24 06:14:18 2002
@@ -15,7 +15,7 @@
     #   * XMLParser::XMLTreeParser
     #   * XMLParser::XMLStreamParser (fastest)
     #   * XMLParser::REXMLStreamParser
-    DEFAULT_PARSER = XMLParser::NQXMLStreamParser 
+    DEFAULT_PARSER = XMLParser::XMLStreamParser
 
     # enable <nil/> tag
     ENABLE_NIL_CREATE    = false
