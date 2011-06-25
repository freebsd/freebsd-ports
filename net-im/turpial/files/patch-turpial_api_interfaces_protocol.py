--- turpial/api/interfaces/protocol.py.orig	2011-03-23 17:50:07.000000000 +0100
+++ turpial/api/interfaces/protocol.py	2011-05-07 22:14:22.000000000 +0200
@@ -280,7 +280,7 @@
         
     def get_str_time(self, strdate):
         t = self.convert_time(strdate)
-        return time.strftime('%b %d, %I:%M %p', t)
+        return time.strftime('%Y-%m-%d @ %H:%M', t)
         
     def get_int_time(self, strdate):
         t = self.convert_time(strdate)
