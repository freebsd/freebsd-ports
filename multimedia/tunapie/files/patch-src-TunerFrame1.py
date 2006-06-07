$FreeBSD$
--- src/TunerFrame1.py	Tue May  9 23:17:31 2006
+++ src/TunerFrame1.py.port	Wed May 10 11:38:29 2006
@@ -352,10 +352,10 @@
         for name in self.favname:
             self.favorites.Append(name)
         self.name=[]
-        self.mediaplayer='/usr/bin/xmms'
-        self.videoplayer='/usr/bin/mplayer -nojoystick'
-        self.term='/usr/bin/x-terminal-emulator'
-        self.ripper='/usr/bin/streamripper -t -u winamp2 -o never'
+        self.mediaplayer='%%X11BASE%%/bin/xmms'
+        self.videoplayer='%%LOCALBASE%%/bin/mplayer -nojoystick'
+        self.term='%%X11BASE%%/bin/xterm'
+        self.ripper='%%LOCALBASE%%/bin/streamripper -t -u winamp2 -o never'
         self.rdir=self.home+'/.tunapie/streamripper'
         self.shoutice=1 #0 is icecast server 1 is shoutcast
         self.mediaplayer,self.videoplayer,self.term,self.ripper,self.rdir,self.shoutice=\
