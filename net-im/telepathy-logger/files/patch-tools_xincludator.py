--- tools/xincludator.py.orig	2020-09-23 16:17:54 UTC
+++ tools/xincludator.py
@@ -1,17 +1,19 @@
 #!/usr/bin/env python
 
+import sys
 from sys import argv, stdout, stderr
 import codecs, locale
 import os
 import xml.dom.minidom
 
-stdout = codecs.getwriter('utf-8')(stdout)
+if sys.version_info[0] < 3:
+    stdout = codecs.getwriter('utf-8')(stdout)
 
 NS_XI = 'http://www.w3.org/2001/XInclude'
 
 def xincludate(dom, base, dropns = []):
     remove_attrs = []
-    for i in xrange(dom.documentElement.attributes.length):
+    for i in range(dom.documentElement.attributes.length):
         attr = dom.documentElement.attributes.item(i)
         if attr.prefix == 'xmlns':
             if attr.localName in dropns:
@@ -34,6 +36,11 @@ if __name__ == '__main__':
     argv = argv[1:]
     dom = xml.dom.minidom.parse(argv[0])
     xincludate(dom, argv[0])
-    xml = dom.toxml()
+
+    if sys.version_info[0] >= 3:
+        xml = dom.toxml(encoding=None)
+    else:
+        xml = dom.toxml()
+
     stdout.write(xml)
     stdout.write('\n')
