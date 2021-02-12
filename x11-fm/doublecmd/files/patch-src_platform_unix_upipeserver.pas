--- src/platform/unix/upipeserver.pas.orig	2020-12-31 11:38:58 UTC
+++ src/platform/unix/upipeserver.pas
@@ -30,9 +30,13 @@ function GetPipeFileName(const FileName: String; Globa
 
 implementation
 
+{$IF DEFINED(LINUX) OR DEFINED(FREEBSD)}
+  {$DEFINE USE_XDG}
+{$ENDIF}
+
 uses
   SimpleIPC, BaseUnix, uPollThread
-{$IF DEFINED(LINUX)}
+{$IF DEFINED(USE_XDG)}
   , uXdg
 {$ENDIF}
   ;
@@ -65,7 +69,7 @@ Type
 
 function GetPipeFileName(const FileName: String; Global : Boolean): String;
 begin
-{$IF DEFINED(LINUX)}
+{$IF DEFINED(USE_XDG)}
   Result:= IncludeTrailingBackslash(GetUserRuntimeDir) + FileName;
 {$ELSE}
   Result:= GetTempDir(Global) + ApplicationName + '-' + IntToStr(fpGetUID) + PathDelim + FileName;
@@ -89,7 +93,7 @@ begin
 end;
 
 constructor TPipeServerComm.Create(AOWner: TSimpleIPCServer);
-{$IF NOT DEFINED(LINUX)}
+{$IF NOT DEFINED(USE_XDG)}
 var
   Info: TStat;
   Directory: String;
@@ -101,7 +105,7 @@ begin
     FFileName:= FFileName + '-' + IntToStr(fpGetPID);
   if FFileName[1] <> '/' then
     FFileName:= GetPipeFileName(FFileName, Owner.Global);
-{$IF NOT DEFINED(LINUX)}
+{$IF NOT DEFINED(USE_XDG)}
   // Verify directory owner
   Directory:= ExtractFileDir(FFileName);
   if not DirectoryExists(Directory) then
