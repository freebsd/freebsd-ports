--- istanbul/main/prefs.py
+++ istanbul/main/prefs.py	2005-07-02 19:37:21.000000000 +0200
@@ -61,7 +61,7 @@
         state = button.get_active()
         self.xml.get_widget('filenameLabel').set_sensitive(state)
         self.xml.get_widget('filenameEntry').set_sensitive(state)
-        self.xml.get_widget('encode_later').set_senisitive(state)
+        self.xml.get_widget('encode_later').set_sensitive(state)
 
     def icecast_toggled_cb(self, button):
         state = button.get_active()
