--- bigboard/stocks/apps/appbrowser.py	2008-05-28 12:46:40.000000000 +0530
+++ bigboard/stocks/apps/appbrowser.py.new	2008-05-28 12:47:15.000000000 +0530
@@ -56,7 +56,7 @@
       
         self.__more_info = IconLink(text="More Info", prelight=False, img_scale_width=16, img_scale_height=16, spacing=2, underline=pango.UNDERLINE_LOW, xalign=hippo.ALIGNMENT_START)
         self.__more_info.link.connect("button-press-event", lambda l,e: self.emit("more-info", self.__app)) 
-        self.__more_info.img.set_property('image-name', '/usr/share/icons/gnome/16x16/status/info.png')
+        self.__more_info.img.set_property('image-name', '%%LOCALBASE%%/share/icons/gnome/16x16/status/info.png')
         self.__controls_box.append(self.__more_info) 
 
         self.__check_showing = CanvasCheckbox("Show in sidebar")
@@ -111,10 +111,10 @@
         
         self.__controls_box.set_child_visible(self.__more_info, not self.__app.is_local())
         if app.is_installed():
-            self.__action_button_image.set_property("image-name", "/usr/share/icons/gnome/16x16/actions/gnome-run.png")
+            self.__action_button_image.set_property("image-name", "%%LOCALBASE%%/share/icons/gnome/16x16/actions/gnome-run.png")
             self.__action_button.set_label_text("Run...")
         else:
-            self.__action_button_image.set_property("image-name", "/usr/share/icons/gnome/16x16/apps/system-software-installer.png")
+            self.__action_button_image.set_property("image-name", "%%LOCALBASE%%/share/icons/gnome/16x16/apps/system-software-installer.png")
             self.__action_button.set_label_text("Install...")
         
     def launch(self):
