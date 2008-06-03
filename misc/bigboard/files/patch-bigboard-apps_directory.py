--- bigboard/apps_directory.py~	2008-03-25 20:09:55.000000000 +0530
+++ bigboard/apps_directory.py	2008-06-02 05:51:42.000000000 +0530
@@ -9,7 +9,7 @@
     def __init__(self):
         gobject.GObject.__init__(self)
         self._logger = logging.getLogger('bigboard.AppsDirectory')
-        self._tree = gmenu.lookup_tree('applications.menu', gmenu.FLAGS_INCLUDE_EXCLUDED)
+        self._tree = gmenu.lookup_tree('gnome-applications.menu', gmenu.FLAGS_INCLUDE_EXCLUDED)
         self._apps = {}
         # with gnome-menus-2.16.0-2.fc6 omitting the user_data arg crashes the gmenu module
         self._tree.add_monitor(self._on_apps_changed, None)
