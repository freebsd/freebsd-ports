--- ./fastest_sites-20081104.py.orig	2011-03-09 21:42:34.682812592 -0500
+++ ./fastest_sites-20081104.py	2011-03-09 21:42:44.067806352 -0500
@@ -66,6 +66,9 @@
     self._host = host
     self._port = AsyncConnect.schemes[scheme]
 
+  def handle_error(self):
+    pass
+
   def handle_connect(self):
     pass
 
