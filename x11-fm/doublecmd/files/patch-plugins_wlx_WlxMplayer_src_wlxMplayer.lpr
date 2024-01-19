--- plugins/wlx/WlxMplayer/src/wlxMplayer.lpr.orig	2023-12-15 21:28:19 UTC
+++ plugins/wlx/WlxMplayer/src/wlxMplayer.lpr
@@ -263,7 +263,7 @@ var
   sPlayerPath: String;
   p: TMPlayer;
 begin
-  pf:= TExProcess.Create('which mplayer');
+  pf:= TExProcess.Create('%%LOCALBASE%%/bin/mplayer');
   try
     pf.Execute;
     if (pf.RezList.Count <> 0) then
