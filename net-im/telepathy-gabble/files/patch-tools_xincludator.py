--- tools/xincludator.py.orig	2014-05-07 14:28:02 UTC
+++ tools/xincludator.py
@@ -1,17 +1,17 @@
 #!/usr/bin/python
 
 from sys import argv, stdout, stderr
-import codecs, locale
-import os
+import locale
+import os, sys
 import xml.dom.minidom
 
-stdout = codecs.getwriter('utf-8')(stdout)
+sys.stdout.reconfigure(encoding='utf-8')
 
 NS_XI = 'http://www.w3.org/2001/XInclude'
 
 def xincludate(dom, base, dropns = []):
     remove_attrs = []
-    for i in xrange(dom.documentElement.attributes.length):
+    for i in range(dom.documentElement.attributes.length):
         attr = dom.documentElement.attributes.item(i)
         if attr.prefix == 'xmlns':
             if attr.localName in dropns:
@@ -35,5 +35,5 @@ if __name__ == '__main__':
     dom = xml.dom.minidom.parse(argv[0])
     xincludate(dom, argv[0])
     xml = dom.toxml()
-    stdout.write(xml)
-    stdout.write('\n')
+    sys.stdout.write(xml)
+    sys.stdout.write('\n')
