--- src/TunerFrame1.py	Wed Jan 10 00:41:00 2007
+++ src/TunerFrame1.py.port	Mon Jan 29 11:32:44 2007
@@ -130,7 +130,7 @@
         self.SetBackgroundColour(wx.Colour(246, 246, 246))
         self.SetBackgroundStyle(wx.BG_STYLE_SYSTEM)
         self.SetThemeEnabled(True)
-        self.SetIcon(wx.Icon('pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
+        self.SetIcon(wx.Icon('%%DATADIR%%/pixmaps/tplogo.xpm',wx.BITMAP_TYPE_XPM))
         self.SetFont(wx.Font(10, wx.SWISS, wx.NORMAL, wx.NORMAL, False,u'Sans'))
         self.SetAutoLayout(True)
         self.SetMinSize(wx.Size(770, 410))
@@ -568,9 +568,13 @@
         self.shoutice=1 #0 is icecast server 1 is shoutcast
         self.maxd=100
         self.newsize=8
+	self.mediaplayer='%%AUDIOPLAYER%%'
+	self.videoplayer='%%VIDEOPLAYER%%'
+	self.term='%%X11BASE%%/bin/xterm'
+	self.ripper='%%LOCALBASE%%/bin/streamripper -t -u winamp2 -o never'
         self.mediaplayer,self.videoplayer,self.term,self.ripper,self.rdir,\
-            self.shoutice,self.maxd,self.newsize=tuner.readprefs(self.home, self.rdir,\
-            self.shoutice,self.maxd,self.newsize)
+            self.shoutice,self.maxd,self.newsize=tuner.readprefs(self.home,self.mediaplayer,\
+            self.videoplayer,self.term,self.ripper,self.rdir,self.shoutice,self.maxd,self.newsize)
         missing_players=[]
         if (commands.getoutput("which "+self.mediaplayer))=="":
             if commands.getoutput("which audacious"):
@@ -1224,7 +1228,8 @@
         finally:
             dlg.Destroy()
         self.mediaplayer,self.videoplayer,self.term,self.ripper,self.rdir,\
-            self.shoutice,self.maxd,self.newsize=tuner.readprefs(self.home,self.rdir,self.shoutice,self.maxd,self.newsize)
+            self.shoutice,self.maxd,self.newsize=tuner.readprefs(self.home,self.mediaplayer,
+            self.videoplayer,self.term,self.ripper,self.rdir,self.shoutice,self.maxd,self.newsize)
         self.setfontsize()
         self.download()
         self.OnRadioradioRadiobutton(1)
