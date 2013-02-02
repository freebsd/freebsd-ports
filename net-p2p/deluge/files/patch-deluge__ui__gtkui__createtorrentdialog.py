--- ./deluge/ui/gtkui/createtorrentdialog.py.orig	2012-04-10 05:53:16.000000000 +0400
+++ ./deluge/ui/gtkui/createtorrentdialog.py	2013-02-02 13:13:21.000000000 +0400
@@ -159,7 +159,7 @@
             chooser.destroy()
             return
 
-        path = result.decode('utf-8').encode(sys.getfilesystemencoding())
+        path = result.decode('utf-8')
 
         self.files_treestore.clear()
         self.files_treestore.append(None, [result, gtk.STOCK_FILE, deluge.common.get_path_size(path)])
@@ -187,7 +187,7 @@
             chooser.destroy()
             return
 
-        path = result.decode('utf-8').encode(sys.getfilesystemencoding())
+        path = result.decode('utf-8')
 
         self.files_treestore.clear()
         self.files_treestore.append(None, [result, gtk.STOCK_OPEN, deluge.common.get_path_size(path)])
