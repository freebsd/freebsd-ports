--- sphinx/writers/html.py.orig	2016-10-01 15:14:37 UTC
+++ sphinx/writers/html.py
@@ -16,6 +16,7 @@ import copy
 import warnings
 
 from six import string_types
+import docutils
 from docutils import nodes
 from docutils.writers.html4css1 import Writer, HTMLTranslator as BaseTranslator
 
@@ -497,6 +498,16 @@ class HTMLTranslator(BaseTranslator):
                     if 'height' not in node:
                         node['height'] = str(size[1])
         BaseTranslator.visit_image(self, node)
+
+    # overwritten
+    def depart_image(self, node):
+        if docutils.__version__ >= "0.13":
+            # since docutils-0.13, HTMLWriter does not push context data on visit_image()
+            if node['uri'].lower().endswith(('svg', 'svgz')):
+                self.body.append(self.context.pop())
+        else:
+            # docutils-0.12 or below, HTML Writer always push context data on visit_image()
+            self.body.append(self.context.pop())
 
     def visit_toctree(self, node):
         # this only happens when formatting a toc from env.tocs -- in this
