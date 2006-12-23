--- src/TunerFrame1.py	Thu Dec 21 00:40:08 2006
+++ src/TunerFrame1.py.port	Fri Dec 22 23:05:45 2006
@@ -129,7 +129,7 @@
         self.SetBackgroundColour(wx.Colour(246, 246, 246))
         self.SetBackgroundStyle(wx.BG_STYLE_SYSTEM)
         self.SetThemeEnabled(True)
-        self.SetIcon(wx.Icon('pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
+        self.SetIcon(wx.Icon('%%DATADIR%%/pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
         self.SetFont(wx.Font(10, wx.SWISS, wx.NORMAL, wx.NORMAL, False,u'Sans'))
         self.SetAutoLayout(True)
         self.SetMinSize(wx.Size(770, 410))
@@ -564,10 +564,10 @@
         for name in self.favname:
             self.favorites.Append(name)
         self.name=[]
-        self.mediaplayer='/usr/bin/xmms'
-        self.videoplayer='/usr/bin/totem'
-        self.term='/usr/bin/x-terminal-emulator'
-        self.ripper='/usr/bin/streamripper -t -u winamp2 -o never'
+        self.mediaplayer='%%X11BASE%%/bin/xmms'
+        self.videoplayer='%%VIDEOPLAYER%%'
+        self.term='%%X11BASE%%/bin/xterm'
+        self.ripper='%%LOCALBASE%%/bin/streamripper -t -u winamp2 -o never'
         self.rdir=self.home+'/.tunapie/streamripper'
         self.shoutice=1 #0 is icecast server 1 is shoutcast
         self.maxd=100
