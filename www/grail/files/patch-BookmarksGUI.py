--- ancillary/BookmarksGUI.py.orig	Sun Mar 28 06:26:45 1999
+++ ancillary/BookmarksGUI.py	Sun Mar  5 08:07:12 2000
@@ -1096,7 +1096,7 @@
         if at_end:
             parent.append_child(node)
         else:
-            parenr.insert_child(node, 0)
+            parent.insert_child(node, 0)
         # scroll the newly added node into view
         self.set_modflag(1)
         self.root_redisplay()
