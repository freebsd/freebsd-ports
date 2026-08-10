--- plugins/wlx/wlxmplayer/src/wlxMplayer.lpr.orig	2026-07-18 09:01:48 UTC
+++ plugins/wlx/wlxmplayer/src/wlxMplayer.lpr
@@ -194,7 +194,7 @@ var
 function ListLoad(ParentWin: HWND; FileToLoad: PAnsiChar; ShowFlags: Integer): HWND; dcpcall;
 var
   Player: TMPlayer;
-  PlayerPath: String = 'mplayer';
+  PlayerPath: String = '%%LOCALBASE%%/bin/mplayer';
 begin
   if not CheckParent(ParentWin) then
     Exit(wlxInvalidHandle);
