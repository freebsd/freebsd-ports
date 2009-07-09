--- portable/util.py.orig	2009-06-26 13:15:52.000000000 +0900
+++ portable/util.py	2009-07-06 02:26:25.000000000 +0900
@@ -752,7 +752,11 @@
         self.__add(data)
 
     def handle_charref(self, ref):
-        self.__add(unichr(int(ref)))
+        if ref.startswith('x'):
+            charnum = int(ref[1:], 16)
+        else:
+            charnum = int(ref)
+        self.__add(unichr(charnum))
 
     def start_p(self, attributes):
         self.__add("\n")
