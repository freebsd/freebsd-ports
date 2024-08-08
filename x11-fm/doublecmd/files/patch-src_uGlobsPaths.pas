--- src/uGlobsPaths.pas.orig	2024-07-22 23:07:50 UTC
+++ src/uGlobsPaths.pas
@@ -3,7 +3,7 @@ unit uGlobsPaths;
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%DATADIR%%/';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
   gpGlobalCfgDir : String = '';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
@@ -12,6 +12,7 @@ var
   gpHighPath : String = ''; // editor highlighter directory
   gpCacheDir : String = ''; // cache directory
   gpThumbCacheDir : String = ''; // thumbnails cache directory
+  gpDocsDir : String = '%%DOCSDIR%%/'; // directory for help files
 
 //Global Configuration Filename
 const
@@ -87,7 +88,7 @@ procedure Initialize;
 begin
   gpExeFile := ParamStr(0);
   gpExeFile := TryReadAllLinks(gpExeFile);
-  gpExePath := ExtractFilePath(gpExeFile);
+  //gpExePath := ExtractFilePath(gpExeFile);
   gpGlobalCfgDir := gpExePath + 'settings' + DirectorySeparator;
 end;
 
