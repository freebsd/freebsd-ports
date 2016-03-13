--- src/uGlobsPaths.pas.orig	2016-01-13 13:34:19 UTC
+++ src/uGlobsPaths.pas
@@ -3,13 +3,14 @@ unit uGlobsPaths;
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%DATADIR%%/';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
   gpGlobalCfgDir : String = '';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
   gpLngDir : String = '';  // path to language *.po files
   gpPixmapPath : String = '';  // path to pixmaps
   gpCacheDir : String = ''; // cache directory
+  gpDocsDir : String = '%%DOCSDIR%%'; // directory for help files
 
 //Global Configuration Filename
 const
@@ -36,7 +37,7 @@ end;
 procedure LoadPaths;
 begin
   OnGetApplicationName := @GetAppName;
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
+  //gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
   DCDebug('Executable directory: ', gpExePath);
   
   gpGlobalCfgDir := gpExePath;
