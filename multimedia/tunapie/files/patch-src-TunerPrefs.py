--- src/TunerPrefs.py	Wed Jul 26 23:26:38 2006
+++ src/TunerPrefs.py.port	Sat Jul 29 07:02:36 2006
@@ -77,7 +77,7 @@
 
         self.audiopath = wx.TextCtrl(id=wxID_PREFERENCESAUDIOPATH,
               name='audiopath', parent=self, pos=wx.Point(168, 16),
-              size=wx.Size(200, 22), style=0, value='/usr/bin/xmms')
+              size=wx.Size(200, 22), style=0, value='%%X11BASE%%/bin/xmms')
         self.audiopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.audiopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -86,7 +86,7 @@
 
         self.videopath = wx.TextCtrl(id=wxID_PREFERENCESVIDEOPATH,
               name='videopath', parent=self, pos=wx.Point(168, 48),
-              size=wx.Size(200, 22), style=0, value='/usr/bin/mplayer')
+              size=wx.Size(200, 22), style=0, value='%%VIDEOPLAYER%%')
         self.videopath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.videopath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -115,7 +115,7 @@
         self.termpath = wx.TextCtrl(id=wxID_PREFERENCESTERMPATH,
               name='termpath', parent=self, pos=wx.Point(168, 80),
               size=wx.Size(200, 22), style=0,
-              value='/usr/bin/x-terminal-emulator')
+              value='%%X11BASE%%/bin/xterm')
         self.termpath.SetFont(wx.Font(7, wx.SWISS, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.termpath.SetBackgroundColour(wx.Colour(255, 253, 239))
@@ -124,7 +124,7 @@
 
         self.rippath = wx.TextCtrl(id=wxID_PREFERENCESRIPPATH, name='rippath',
               parent=self, pos=wx.Point(168, 112), size=wx.Size(200, 22),
-              style=0, value='/usr/bin/streamripper')
+              style=0, value='%%LOCALBASE%%/bin/streamripper')
         self.rippath.SetFont(wx.Font(7, 77, wx.NORMAL, wx.NORMAL, False,
               u'Sans'))
         self.rippath.SetBackgroundColour(wx.Colour(255, 253, 239))
