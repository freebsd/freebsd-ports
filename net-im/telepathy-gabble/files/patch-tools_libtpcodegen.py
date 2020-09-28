--- tools/libtpcodegen.py.orig	2014-05-07 14:28:02 UTC
+++ tools/libtpcodegen.py
@@ -167,7 +167,10 @@ class _SignatureIter:
     def __init__(self, string):
         self.remaining = string
 
-    def next(self):
+    def __iter__(self):
+        self
+
+    def __next__(self):
         if self.remaining == '':
             raise StopIteration
 
