--- lib/config.rb.orig	Sun Jan 26 00:07:14 2003
+++ lib/config.rb	Sun Jan 26 20:10:15 2003
@@ -16,7 +16,7 @@
     #   * XMLParser::XMLStreamParser (fastest)
     #   * XMLParser::REXMLStreamParser
     #   * XMLParser::XMLScanStreamParser
-    DEFAULT_PARSER = XMLParser::NQXMLStreamParser 
+    DEFAULT_PARSER = XMLParser::XMLStreamParser
 
     # enable <nil/> tag
     ENABLE_NIL_CREATE    = false
