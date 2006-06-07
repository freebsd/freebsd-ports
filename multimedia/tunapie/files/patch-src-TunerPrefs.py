$FreeBSD$
--- src/TunerPrefs.py	Wed May 24 23:10:23 2006
+++ src/TunerPrefs.py.port	Sat May 27 10:59:16 2006
@@ -74,7 +74,7 @@
 
         self.audiopath = wx.TextCtrl(id=wxID_PREFERENCESAUDIOPATH,
               name='audiopath', parent=self, pos=wx.Point(160, 16),
-              size=wx.Size(208, 22), style=0, value='/usr/bin/xmms')
+              size=wx.Size(208, 22), style=0, value='%%X11BASE%%/bin/xmms')
         self.audiopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.audiopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -82,7 +82,7 @@
 
         self.videopath = wx.TextCtrl(id=wxID_PREFERENCESVIDEOPATH,
               name='videopath', parent=self, pos=wx.Point(160, 48),
-              size=wx.Size(208, 22), style=0, value='/usr/bin/mplayer')
+              size=wx.Size(208, 22), style=0, value='%%LOCALBASE%%/bin/mplayer')
         self.videopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.videopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -110,7 +110,7 @@
         self.termpath = wx.TextCtrl(id=wxID_PREFERENCESTERMPATH,
               name='termpath', parent=self, pos=wx.Point(160, 80),
               size=wx.Size(208, 22), style=0,
-              value='/usr/bin/x-terminal-emulator')
+              value='%%X11BASE%%/bin/xterm')
         self.termpath.SetFont(wx.Font(7, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.termpath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -118,7 +118,7 @@
 
         self.rippath = wx.TextCtrl(id=wxID_PREFERENCESRIPPATH, name='rippath',
               parent=self, pos=wx.Point(160, 112), size=wx.Size(208, 22),
-              style=0, value='/usr/bin/streamripper')
+              style=0, value='%%LOCALBASE%%/bin/streamripper')
         self.rippath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.rippath.SetBackgroundColour(wx.Colour(255, 253, 239))
