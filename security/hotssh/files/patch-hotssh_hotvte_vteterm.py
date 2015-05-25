--- hotssh/hotvte/vteterm.py.orig
+++ hotssh/hotvte/vteterm.py
@@ -264,7 +264,7 @@
     def __set_gtk_colors(self):
         fg = self.style.text[gtk.STATE_NORMAL]
         bg = self.style.base[gtk.STATE_NORMAL]
-        self.set_colors(True, fg, bg, isdefault=True)
+        self.set_colors(fg, bg, False, isdefault=True)
         
     def set_colors(self, fg, bg, palette, isdefault=False):
         if not isdefault:
