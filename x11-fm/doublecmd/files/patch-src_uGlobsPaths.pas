--- src/uGlobsPaths.pas.orig	2017-12-11 10:45:31 UTC
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
+  gpDocsDir : String = '%%DOCSDIR%%'; // directory for help files
 
 //Global Configuration Filename
 const
@@ -37,7 +38,7 @@ end;
 procedure LoadPaths;
 begin
   OnGetApplicationName := @GetAppName;
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
+  //gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
   DCDebug('Executable directory: ', gpExePath);
   
   gpGlobalCfgDir := gpExePath;
