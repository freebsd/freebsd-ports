--- src/lib/Config.py.orig	Sun Nov 16 03:57:07 2003
+++ src/lib/Config.py	Sun Nov 16 03:58:04 2003
@@ -364,6 +364,8 @@
     last_poll = property(get_last_poll, set_last_poll, None, "Last polled")
 
     def get_number_of_items_stored(self):
+	if self._items_stored == 0:
+	    return 30
         return self._items_stored
 
     def set_number_of_items_stored(self, num=30):
