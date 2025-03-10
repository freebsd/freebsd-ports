--- plugins/wlx/WlxMplayer/src/wlxMplayer.lpr.orig	2025-01-18 20:01:52 UTC
+++ plugins/wlx/WlxMplayer/src/wlxMplayer.lpr
@@ -263,7 +263,7 @@ begin
   sPlayerPath: String;
   p: TMPlayer;
 begin
-  pf:= TExProcess.Create('which mplayer');
+  pf:= TExProcess.Create('%%LOCALBASE%%/bin/mplayer');
   try
     pf.Execute;
     if (pf.RezList.Count <> 0) then
