
$FreeBSD$

--- edit.py.orig	Fri May 11 16:44:12 2001
+++ edit.py	Fri May 11 19:30:04 2001
@@ -444,9 +444,8 @@
     ##
     ##
     def create_menu(self):
-        from prefix import PYGMY_PREFIX
+        from prefix import PYGMY_ICONDIR
         import os.path
-        icondir = os.path.join(PYGMY_PREFIX, "share/pixmaps/pygmy")
 
         file_menu = [
             UIINFO_ITEM_STOCK('Insert File', None, self.insert_file, STOCK_MENU_OPEN),
@@ -470,7 +469,7 @@
                               STOCK_MENU_TIMER),
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Security', None, self.privacy_dialog,
-                              icondir+"/encrypt.xpm"), 
+                              PYGMY_ICONDIR+"/encrypt.xpm"), 
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Add Signature', None, self.add_sig,
                               STOCK_MENU_BLANK), 
