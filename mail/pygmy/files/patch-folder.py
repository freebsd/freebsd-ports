
$FreeBSD$

--- folder.py.orig	Fri May 11 16:44:12 2001
+++ folder.py	Fri May 11 19:33:58 2001
@@ -371,23 +371,22 @@
     ##
     ##
     def init_pixmaps(self):
-        from prefix import PYGMY_PREFIX
-        icondir = os.path.join(PYGMY_PREFIX, "share/pixmaps/pygmy")
+        from prefix import PYGMY_ICONDIR
         # Create a pixmaps
         self.open_dir, self.open_dir_mask = create_pixmap_from_xpm(self.win, None,
-                                                                   icondir+"/dir-open.xpm")
+                                                                   PYGMY_ICONDIR+"/dir-open.xpm")
         self.close_dir, self.close_dir_mask = create_pixmap_from_xpm(self.win, None,
-                                                                     icondir+"/dir-close.xpm")
+                                                                     PYGMY_ICONDIR+"/dir-close.xpm")
         self.trash, self.trash_mask = create_pixmap_from_xpm(self.win, None,
-                                                             icondir+"/trash.xpm")
+                                                             PYGMY_ICONDIR+"/trash.xpm")
         self.inbox, self.inbox_mask = create_pixmap_from_xpm(self.win, None,
-                                                             icondir+"/inbox.xpm")
+                                                             PYGMY_ICONDIR+"/inbox.xpm")
         self.outbox, self.outbox_mask = create_pixmap_from_xpm(self.win, None,
-                                                               icondir+"/outbox.xpm")
+                                                               PYGMY_ICONDIR+"/outbox.xpm")
         self.empty, self.empty_mask = create_pixmap_from_xpm(self.win, None,
-                                                             icondir+"/tray_empty.xpm")
+                                                             PYGMY_ICONDIR+"/tray_empty.xpm")
         self.full, self.full_mask = create_pixmap_from_xpm(self.win, None,
-                                                           icondir+"/tray_full.xpm")
+                                                           PYGMY_ICONDIR+"/tray_full.xpm")
 
     ##
     ## Method create_menu (self)
@@ -396,8 +395,7 @@
     ##
     ##
     def create_menu(self):
-        from prefix import PYGMY_PREFIX
-        icondir = os.path.join(PYGMY_PREFIX, "share/pixmaps/pygmy")
+        from prefix import PYGMY_ICONDIR
         
         file_menu = [
             UIINFO_ITEM_STOCK('Save As...', None, self.saveas, STOCK_MENU_SAVE_AS),
@@ -442,7 +440,7 @@
             UIINFO_ITEM_STOCK('Reply', None, self.reply_callback,
                               STOCK_MENU_MAIL_RPL),
             UIINFO_ITEM_STOCK('Reply All', None, self.replyall_callback,
-                              STOCK_MENU_MAIL_RPL),
+                              PYGMY_ICONDIR+"/reply_to_all_menu.xpm"),
             UIINFO_ITEM_STOCK('Forward', None, self.forward_callback,
                               STOCK_MENU_MAIL_FWD),
             UIINFO_ITEM_STOCK('Delete', None, self.trash_msg,
@@ -451,14 +449,14 @@
                               STOCK_MENU_OPEN),
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Move', None, self.move_msg,
-                              icondir+"/move_message.xpm"),
+                              PYGMY_ICONDIR+"/move_message.xpm"),
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Next', None, self.next_msg_callback,
                               STOCK_MENU_FORWARD), 
             UIINFO_ITEM_STOCK('Prev', None, self.prev_msg_callback,
                               STOCK_MENU_BACK), 
             UIINFO_SEPARATOR,
-            UIINFO_SUBTREE_STOCK('Mark', mark_menu, icondir+"/mark.xpm")
+            UIINFO_SUBTREE_STOCK('Mark', mark_menu, PYGMY_ICONDIR+"/mark.xpm")
            ]
         tools_menu = [
             UIINFO_ITEM_STOCK('Address List', None, self.addresslist, STOCK_MENU_BLANK),
