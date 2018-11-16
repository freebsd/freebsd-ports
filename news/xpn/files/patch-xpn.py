From: David Paleino <dapal@debian.org>
Subject: implement a trayicon, with a context menu, and blinking on new
 posts.

--- xpn.py.orig	2018-11-16 09:23:53 UTC
+++ xpn.py
@@ -329,7 +329,6 @@ class MainWin:
         self.win_outbox=Outbox_Manager(self,VERSION)
         self.win_outbox.show()
 
-            
     def open_edit_win(self,object,is_followup=False):
         group=""
         id_name=""
@@ -396,7 +395,6 @@ class MainWin:
             self.win4=Edit_Win(self.configs,group,None,None,self.subscribed_groups,server_name=self.current_server,id_name=id_name)
             #self.win4.show()
 
-
     def open_edit_mail_win(self,object):
         to_name=""
         id_name=""
@@ -579,6 +577,31 @@ class MainWin:
         except: pass
         gtk.main_quit()
 
+    def tray_activated(self,  widget):
+        if self.window.get_property("is-active"):
+            self.window.iconify()
+            self.window.hide()
+        else:
+            self.window.present()
+            self.window.deiconify()
+            widget.set_blinking(False)
+
+    def tray_popuped(self,  widget,  button,  timestamp):
+        menu = gtk.Menu()
+        menuitem = gtk.ImageMenuItem(gtk.STOCK_PREFERENCES)
+        menuitem.connect("activate",  self.open_configure_win)
+        menu.append(menuitem)
+        menu.append(gtk.SeparatorMenuItem())
+        menuitem = gtk.ImageMenuItem(gtk.STOCK_ABOUT)
+        menuitem.connect('activate', self.open_about_dialog)
+        menu.append(menuitem)
+        menuitem = gtk.ImageMenuItem(gtk.STOCK_QUIT)
+        menuitem.connect('activate', self.destroy)
+        menu.append(menuitem)
+
+        menu.show_all()
+        menu.popup(None,  None,  None,  button,  timestamp)
+
     def save_sorting_type(self,obj=None):
         for n in range(1,5):
             col=self.threads_pane.threads_tree.get_column(n)
@@ -592,9 +615,7 @@ class MainWin:
                 self.configs["ascend_order"]=ascend_order
                 self.configs["sort_col"]=col_name
                 self.conf.write_configs()
-         
-                
-    
+
     def show_subscribed(self):
         model,path_list,iter_list=self.groups_pane.get_selected_rows()
         
@@ -1588,6 +1609,8 @@ class MainWin:
         self.statusbar.push(1,message)
         if total_headers:
             self.progressbar.set_text(_("Building Articles"))
+            if not self.window.get_property("is-active"):
+                self.trayicon.set_blinking(True)
         else:
             self.progressbar.set_text(_("No New Headers"))
         self.progressbar.set_fraction(2/float(2))
@@ -2600,8 +2623,6 @@ When you try to import a newsrc file XPN searches for 
                         article.has_body=False
                     self.art_db.insertArticle(group[0],article)
 
-
-
     def __init__(self,use_home,custom_dir):
         Edit_Win.VERSION=VERSION
         Edit_Mail_Win.VERSION=VERSION
@@ -2615,6 +2636,13 @@ When you try to import a newsrc file XPN searches for 
         if ret>0 :sys.exit(ret)
         self.wdir=userdir.dir
         
+        # handle the trayicon
+        self.trayicon = gtk.StatusIcon()
+        self.trayicon.set_tooltip_text(_("XPN Newsreader"))
+        self.trayicon.set_from_file("pixmaps/xpn-icon.png")
+        self.trayicon.connect("activate",  self.tray_activated)
+        self.trayicon.connect("popup-menu",  self.tray_popuped)
+
         self.conf=Config_File()
         self.configs=self.conf.get_configs()
 
