--- src/TunerFrame1.py	Mon Apr  9 00:35:15 2007
+++ src/TunerFrame1.py.port	Mon Apr  9 16:27:24 2007
@@ -130,7 +130,7 @@
         self.SetBackgroundColour(wx.Colour(246, 246, 246))
         self.SetBackgroundStyle(wx.BG_STYLE_SYSTEM)
         self.SetThemeEnabled(True)
-        self.SetIcon(wx.Icon('pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
+        self.SetIcon(wx.Icon('%%DATADIR%%/pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
         self.SetFont(wx.Font(10, wx.SWISS, wx.NORMAL, wx.NORMAL, False,u'Sans'))
         self.SetAutoLayout(True)
         self.SetMinSize(wx.Size(770, 410))
