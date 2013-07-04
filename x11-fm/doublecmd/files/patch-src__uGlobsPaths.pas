--- ./src/uGlobsPaths.pas.orig	2013-06-30 19:29:19.097919000 +0200
+++ ./src/uGlobsPaths.pas	2013-06-30 19:22:37.387062000 +0200
@@ -3,14 +3,15 @@
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
 
 implementation
@@ -26,7 +27,7 @@
 procedure LoadPaths;
 begin
   OnGetApplicationName := @GetAppName;
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
+  //gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrU(0)));
   DCDebug('Executable directory: ', gpExePath);
   
   gpGlobalCfgDir := gpExePath;
