--- src/uGlobsPaths.pas.orig	2024-01-04 17:03:35 UTC
+++ src/uGlobsPaths.pas
@@ -3,7 +3,7 @@ unit uGlobsPaths;
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%DATADIR%%/';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
   gpGlobalCfgDir : String = '';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
@@ -11,6 +11,7 @@ var
   gpPixmapPath : String = '';  // path to pixmaps
   gpHighPath : String = ''; // editor highlighter directory
   gpThumbCacheDir : String = ''; // thumbnails cache directory
+  gpDocsDir : String = '%%DOCSDIR%%/'; // directory for help files
 
 //Global Configuration Filename
 const
@@ -74,7 +75,7 @@ end;
 
 procedure Initialize;
 begin
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStr(0)));
+  //gpExePath := ExtractFilePath(TryReadAllLinks(ParamStr(0)));
   gpGlobalCfgDir := gpExePath + 'settings' + DirectorySeparator;
 end;
 
