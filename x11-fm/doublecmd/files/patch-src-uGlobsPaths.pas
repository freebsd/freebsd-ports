--- src/uGlobsPaths.pas	2012-03-31 18:38:11.000000000 -0500
+++ src/uGlobsPaths.pas	2012-03-31 18:51:02.000000000 -0500
@@ -3,7 +3,7 @@
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%PREFIX%%/bin';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
   gpGlobalCfgDir : String = '';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
@@ -26,10 +26,10 @@
 procedure LoadPaths;
 begin
   OnGetApplicationName := @GetAppName;
-  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrUTF8(0)));
+//  gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrUTF8(0)));
   DCDebug('Executable directory: ', gpExePath);
   
-  gpGlobalCfgDir := gpExePath;
+  gpGlobalCfgDir := '%%DATADIR%%';
   if gpCmdLineCfgDir <> EmptyStr then
   begin
     if GetPathType(gpCmdLineCfgDir) <> ptAbsolute then
@@ -48,12 +48,12 @@
   end;
 
   gpCfgDir := IncludeTrailingPathDelimiter(gpCfgDir);
-  gpLngDir := gpExePath + 'language' + DirectorySeparator;
-  gpPixmapPath := gpExePath + 'pixmaps' + DirectorySeparator;
+  gpLngDir :=  '%%DATADIR%%/' + 'language' + DirectorySeparator;
+  gpPixmapPath := '%%DATADIR%%/' + 'pixmaps' + DirectorySeparator;
   gpCacheDir := GetAppCacheDir;
 
   // set up environment variables
-  mbSetEnvironmentVariable('commander_path', ExcludeTrailingBackslash(gpExePath));
+  mbSetEnvironmentVariable('commander_path', ExcludeTrailingBackslash('%%DATADIR%%/'));
 end;
 
 end.
