--- Extensions/EpozPostTidy.py.orig	Mon May 10 18:49:57 2004
+++ Extensions/EpozPostTidy.py	Wed May 26 23:54:41 2004
@@ -25,6 +25,8 @@
             # Internal Link?                                
             if tag=="a" and key=="href":
                 value = self.getRelativeUrl(self.pageurl, value)
+            if tag=="img" and key=="src":
+                value = self.getRelativeUrl(self.pageurl, value)
             attributes += ' %s="%s"' % (key,value)            
         self.res += "<%s%s>" % (tag, attributes)
 
@@ -44,7 +46,7 @@
         self.res += "<%s%s />" % (tag, attributes)
         
     def handle_data(self, data):
-        self.res += data.strip()
+        self.res += data
         
     def handle_charref(self, data):
         self.res += "&%s;" % data
