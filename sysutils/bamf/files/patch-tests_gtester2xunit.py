--- tests/gtester2xunit.py.orig	2018-11-07 22:39:11 UTC
+++ tests/gtester2xunit.py
@@ -1,18 +1,17 @@
 #! /usr/bin/python
 from argparse import ArgumentParser
-import libxslt
-import libxml2
 import sys
 import os
+from lxml import etree
 
 XSL_TRANSFORM='/usr/share/gtester2xunit/gtester.xsl'
 
 def transform_file(input_filename, output_filename, xsl_file):
-    gtester = libxml2.parseFile(xsl_file)
-    style = libxslt.parseStylesheetDoc(gtester)
-    doc = libxml2.parseFile(input_filename)
-    result = style.applyStylesheet(doc, None)
-    result.saveFormatFile(filename=output_filename, format=True)
+    gtester = etree.parse(xsl_file)
+    style = etree.XSLT(gtester)
+    doc = etree.parse(input_filename)
+    result = style(doc)
+    result.write(filename=output_filename, format=True)
 
 
 def get_output_filename(input_filename):
