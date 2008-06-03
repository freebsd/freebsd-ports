--- bigboard/stocks/self/SelfStock.py	2008-04-29 02:40:59.000000000 +0530
+++ bigboard/stocks/self/SelfStock.py.new	2008-05-28 12:42:26.000000000 +0530
@@ -131,16 +131,16 @@
 
         self.__mugshot_link = IconLink(img_scale_width=22, img_scale_height=22, xalign=hippo.ALIGNMENT_START)
         self.__mugshot_link.link.connect("activated", self.__show_mugshot_link)
-        self.__mugshot_link.img.set_property('image-name', '/usr/share/icons/gnome/22x22/apps/web-browser.png')
+        self.__mugshot_link.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/22x22/apps/web-browser.png')
         self.__personalization_box.append(self.__mugshot_link)
 
         link = IconLink(text='Desktop Preferences', img_scale_width=22, img_scale_height=22, xalign=hippo.ALIGNMENT_START)
         link.link.connect("activated", self.__on_system_preferences)
-        link.img.set_property('image-name', '/usr/share/icons/gnome/22x22/categories/preferences-system.png')
+        link.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/22x22/categories/preferences-system.png')
         self.__personalization_box.append(link)    
         link = IconLink(text='Sidebar Preferences', img_scale_width=22, img_scale_height=22, xalign=hippo.ALIGNMENT_START)
         link.link.connect("activated", self.__on_sidebar_controls)
-        link.img.set_property('image-name', '/usr/share/icons/gnome/22x22/categories/preferences-desktop.png')
+        link.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/22x22/categories/preferences-desktop.png')
         self.__personalization_box.append(link)
 
         vbox.append(Separator())
@@ -159,7 +159,7 @@
             
             link = IconLink(text='Log in as Another User...', img_scale_width=22, img_scale_height=22, xalign=hippo.ALIGNMENT_START)
             link.link.connect("activated", self.__do_fus_login_other_user)
-            link.img.set_property('image-name', '/usr/share/icons/gnome/22x22/apps/system-users.png')
+            link.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/22x22/apps/system-users.png')
             self.__fus_box.append(link)
             self.__fus_users = []
             self.__handle_fus_change()
@@ -169,7 +169,7 @@
 
         link = IconLink(text='Logout or Shutdown...', img_scale_width=22, img_scale_height=22, xalign=hippo.ALIGNMENT_START)
         link.link.connect("activated", self.__on_logout)
-        link.img.set_property('image-name', '/usr/share/icons/gnome/22x22/apps/gnome-shutdown.png')
+        link.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/22x22/apps/gnome-shutdown.png')
         self.__logout_controls_box.append(link)
 
         self.update_self(myself)
@@ -183,7 +183,7 @@
                 self.__name.set_property("text", myself.name)
             self.__mugshot_link.link.set_property("text", 'Visit Account Page')
         else:
-            self.__photo.set_property("image-name", '/usr/share/pixmaps/nobody.png')
+            self.__photo.set_property("image-name", '%%LOCALBASE%%/share/pixmaps/nobody.png')
             self.__name.set_property("text", "Nobody")
             self.__personalization_box.set_child_visible(self.__mugshot_link, False)
         
@@ -256,7 +256,7 @@
         self._namephoto_box.connect("button-press-event", lambda button, event: self.__on_activate())
         
         self._photo = CanvasMugshotURLImage(scale_width=48, scale_height=48)
-        self._photo.set_property("image-name", '/usr/share/pixmaps/nobody.png')
+        self._photo.set_property("image-name", '%%LOCALBASE%%/share/pixmaps/nobody.png')
         self._namephoto_box.set_photo(self._photo)
         
         self._namephoto_box_child = CanvasHBox()
