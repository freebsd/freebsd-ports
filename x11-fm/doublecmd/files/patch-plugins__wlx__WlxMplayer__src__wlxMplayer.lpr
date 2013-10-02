--- ./plugins/wlx/WlxMplayer/src/wlxMplayer.lpr.orig	2013-03-10 11:26:35.000000000 +0100
+++ ./plugins/wlx/WlxMplayer/src/wlxMplayer.lpr	2013-07-22 22:43:52.577214000 +0200
@@ -258,7 +258,7 @@
   sPlayerPath: String;
   p: TMPlayer;
 begin
-  pf:= TExProcess.Create('which mplayer');
+  pf:= TExProcess.Create('%%LOCALBASE%%/bin/mplayer');
   try
     pf.Execute;
     if (pf.RezList.Count <> 0) then
