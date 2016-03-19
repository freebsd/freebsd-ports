--- plugins/wlx/WlxMplayer/src/wlxMplayer.lpr.orig	2016-01-13 13:19:01 UTC
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
