$FreeBSD$
--- src/TunerFrame1.py	Sun Jul  2 20:16:55 2006
+++ src/TunerFrame1.py.port	Tue Jul  4 15:07:01 2006
@@ -422,10 +422,10 @@
         for name in self.favname:
             self.favorites.Append(name)
         self.name=[]
-        self.mediaplayer='/usr/bin/xmms'
-        self.videoplayer='/usr/bin/totem'
-        self.term='/usr/bin/x-terminal-emulator'
-        self.ripper='/usr/bin/streamripper -t -u winamp2 -o never'
+        self.mediaplayer='%%X11BASE%%/bin/xmms'
+        self.videoplayer='%%X11BASE%%/bin/xine'
+        self.term='%%X11BASE%%/bin/xterm'
+        self.ripper='%%LOCALBASE%%/bin/streamripper -t -u winamp2 -o never'
         self.rdir=self.home+'/.tunapie/streamripper'
         self.shoutice=1 #0 is icecast server 1 is shoutcast
         self.maxd=100
