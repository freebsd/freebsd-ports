--- tools/glib-interfaces-gen.py.orig	2014-05-07 14:28:02 UTC
+++ tools/glib-interfaces-gen.py
@@ -24,13 +24,13 @@ class Generator(object):
         self.spec = get_by_path(dom, "spec")[0]
 
     def h(self, code):
-        self.decls.append(code.encode('utf-8'))
+        self.decls.append(code)
 
     def c(self, code):
-        self.impls.append(code.encode('utf-8'))
+        self.impls.append(code)
 
     def d(self, code):
-        self.docs.append(code.encode('utf-8'))
+        self.docs.append(code)
 
     def __call__(self):
         for f in self.h, self.c:
