--- src/lib/Config.py.orig	Tue Aug 24 02:19:12 2004
+++ src/lib/Config.py	Tue Aug 24 02:20:06 2004
@@ -369,6 +369,8 @@
     last_poll = property(get_last_poll, set_last_poll, doc="Last polled")
 
     def get_number_of_items_stored(self):
+        if self._items_stored == 0:
+            return 30
         return self._items_stored
 
     def set_number_of_items_stored(self, num=30):
