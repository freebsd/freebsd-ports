--- src/platform/udefaultplugins.pas.orig	2017-02-11 15:03:56 UTC
+++ src/platform/udefaultplugins.pas
@@ -287,7 +287,7 @@ begin
 
   if gWdxPlugins.IndexOfName('audioinfo') < 0 then
   begin
-    gWdxPlugins.Add(GetCmdDirFromEnvVar(Folder) + 'audioinfo' + PathDelim + 'audioinfo.wdx');
+    gWdxPlugins.Add(Folder + 'audioinfo' + PathDelim + 'audioinfo.wdx');
   end;
 
   // Wfx plugins
