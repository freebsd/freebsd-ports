--- extconf.rb.orig	Thu Sep 20 00:07:17 2001
+++ extconf.rb	Mon Oct 28 03:12:50 2002
@@ -14,6 +14,8 @@
   have_library('gcc',nil)
 end
 
+have_library('stdc++')
+
 if have_header("sablot.h") and
     ((have_library("expat",    "XML_ParserCreate") and
       have_library("expat",  "XmlParseXmlDecl")) or
