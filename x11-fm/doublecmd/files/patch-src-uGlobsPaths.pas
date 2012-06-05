--- src/uGlobsPaths.pas.old	2012-02-14 04:46:22.000000000 +0100
+++ src/uGlobsPaths.pas	2012-04-24 20:34:12.000000000 +0200
@@ -3,9 +3,9 @@
 interface
 
 var
-  gpExePath : String = '';  // executable directory
+  gpExePath : String = '%%PREFIX%%/bin';  // executable directory
   gpCfgDir : String = '';  // directory from which configuration files are used
-  gpGlobalCfgDir : String = '';  // config dir global for all user
+  gpGlobalCfgDir : String = '%%DATADIR%%';  // config dir global for all user
   gpCmdLineCfgDir : String = ''; // config dir passed on the command line
   gpLngDir : String = '';  // path to language *.po files
   gpPixmapPath : String = '';  // path to pixmaps
@@ -29,7 +29,7 @@
   gpExePath := ExtractFilePath(TryReadAllLinks(ParamStrUTF8(0)));
   DCDebug('Executable directory: ', gpExePath);
   
-  gpGlobalCfgDir := gpExePath;
+  //gpGlobalCfgDir := gpExePath;
   if gpCmdLineCfgDir <> EmptyStr then
   begin
     if GetPathType(gpCmdLineCfgDir) <> ptAbsolute then
@@ -48,13 +48,13 @@
   end;
 
   gpCfgDir := IncludeTrailingPathDelimiter(gpCfgDir);
-  gpLngDir := gpExePath + 'language' + DirectorySeparator;
-  gpPixmapPath := gpExePath + 'pixmaps' + DirectorySeparator;
+  gpLngDir := '%%DATADIR%%/' + 'language' + DirectorySeparator;
+  gpPixmapPath := '%%DATADIR%%/' + 'pixmaps' + DirectorySeparator;
   gpCacheDir := GetAppCacheDir;
 
   // set up environment variables
-  mbSetEnvironmentVariable('COMMANDER_DRIVE', ExtractRootDir(gpExePath));
-  mbSetEnvironmentVariable('COMMANDER_PATH', ExcludeTrailingBackslash(gpExePath));
+  mbSetEnvironmentVariable('COMMANDER_DRIVE', ExtractRootDir('%%DATADIR%%'));
+  mbSetEnvironmentVariable('COMMANDER_PATH', ExcludeTrailingBackslash('%%DATADIR%%'));
 end;
 
 end.
