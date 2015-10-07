--- plugins/wlx/WlxMplayer/src/wlxMplayer.lpr.orig	2013-03-10 10:26:35 UTC
+++ plugins/wlx/WlxMplayer/src/wlxMplayer.lpr
@@ -258,7 +258,7 @@ var
   sPlayerPath: String;
   p: TMPlayer;
 begin
-  pf:= TExProcess.Create('which mplayer');
+  pf:= TExProcess.Create('%%LOCALBASE%%/bin/mplayer');
   try
     pf.Execute;
     if (pf.RezList.Count <> 0) then
