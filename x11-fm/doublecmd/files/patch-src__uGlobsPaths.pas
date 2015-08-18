--- src/uGlobsPaths.pas.orig	2015-08-17 15:35:25 UTC
+++ src/uGlobsPaths.pas
@@ -3,14 +3,15 @@ unit uGlobsPaths;
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%DATADIR%%/';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
   gpGlobalCfgDir : String = '';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
   gpLngDir : String = '';  // path to language *.po files
   gpPixmapPath : String = '';  // path to pixmaps
   gpCacheDir : UTF8String = ''; // cache directory
-  
+  gpDocsDir : String = '%%DOCSDIR%%'; // directory for help files
+
 procedure LoadPaths;
 procedure UpdateEnvironmentVariable;
 
@@ -32,7 +33,7 @@ end;
 procedure LoadPaths;
 begin
   OnGetApplicationName := @GetAppName;
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
+  //gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
   DCDebug('Executable directory: ', gpExePath);
   
   gpGlobalCfgDir := gpExePath;
