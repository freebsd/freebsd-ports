--- src/TunerPrefs.py	Wed Jan 10 00:41:00 2007
+++ src/TunerPrefs.py.port	Sun Jan 28 21:58:34 2007
@@ -94,7 +94,7 @@
 
         self.audiopath = wx.TextCtrl(id=wxID_PREFERENCESAUDIOPATH,
               name='audiopath', parent=self, pos=wx.Point(144, 16),
-              size=wx.Size(224, 22), style=0, value='/usr/bin/xmms')
+              size=wx.Size(224, 22), style=0, value='%%AUDIOPLAYER%%')
         self.audiopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.audiopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -103,7 +103,7 @@
 
         self.videopath = wx.TextCtrl(id=wxID_PREFERENCESVIDEOPATH,
               name='videopath', parent=self, pos=wx.Point(144, 48),
-              size=wx.Size(216, 22), style=0, value='/usr/bin/mplayer')
+              size=wx.Size(216, 22), style=0, value='%%VIDEOPLAYER%%')
         self.videopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.videopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -131,7 +131,7 @@
         self.termpath = wx.TextCtrl(id=wxID_PREFERENCESTERMPATH,
               name='termpath', parent=self, pos=wx.Point(144, 80),
               size=wx.Size(224, 22), style=0,
-              value='/usr/bin/x-terminal-emulator')
+              value='%%X11BASE%%/bin/xterm')
         self.termpath.SetFont(wx.Font(7, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.termpath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -140,7 +140,7 @@
 
         self.rippath = wx.TextCtrl(id=wxID_PREFERENCESRIPPATH, name='rippath',
               parent=self, pos=wx.Point(144, 112), size=wx.Size(224, 22),
-              style=0, value='/usr/bin/streamripper')
+              style=0, value='%%LOCALBASE%%/bin/streamripper')
         self.rippath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.rippath.SetBackgroundColour(wx.Colour(255, 253, 239))
