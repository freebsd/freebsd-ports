--- extconf.rb.orig	Mon Mar 12 02:09:20 2001
+++ extconf.rb	Mon Mar 12 22:00:21 2001
@@ -8,8 +8,10 @@
 end
 
 if have_header("sablot.h") and
-    have_library("xmltok", "XmlParseXmlDecl") and
-    have_library("xmlparse", "XML_ParserCreate") and
+    (have_library("expat", "XML_ParserCreate") or
+     (have_library("xmltok", "XmlParseXmlDecl") and
+      have_library("xmlparse", "XML_ParserCreate"))) and
+    have_library("iconv") and
     have_library("sablot", "SablotProcessStrings")
   create_makefile("sablot")
   STDERR.print <<EOB
