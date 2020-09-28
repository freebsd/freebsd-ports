--- tools/glib-client-gen.py.orig	2014-05-07 14:28:02 UTC
+++ tools/glib-client-gen.py
@@ -74,17 +74,17 @@ class Generator(object):
         self.guard = opts.get('--guard', None)
 
     def h(self, s):
-        if isinstance(s, unicode):
+        if isinstance(s, str):
             s = s.encode('utf-8')
         self.__header.append(s)
 
     def b(self, s):
-        if isinstance(s, unicode):
+        if isinstance(s, str):
             s = s.encode('utf-8')
         self.__body.append(s)
 
     def d(self, s):
-        if isinstance(s, unicode):
+        if isinstance(s, str):
             s = s.encode('utf-8')
         self.__docs.append(s)
 
