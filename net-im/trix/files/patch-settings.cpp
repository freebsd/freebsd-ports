--- src/settings.cpp.orig	2008-06-29 20:24:50.000000000 +0300
+++ src/settings.cpp		2008-07-02 18:31:27.000000000 +0300
@@ -143,11 +143,10 @@
     def_downloadpath=QDir::homeDirPath();
     def_awaylimit=1800;
     def_autoupdateinterval = 300;
-#ifdef BSD
+
     def_playcmd="/usr/local/bin/play";
-#else
-    def_playcmd = "/usr/bin/aplay";
-#endif
+
+
     def_snd[Sound::Chatline] = datapath + "snd/chatline.wav";
     def_snd[Sound::Beep] = datapath + "snd/beep.wav";
     def_snd[Sound::JoinChannel] = datapath + "snd/join.wav";
