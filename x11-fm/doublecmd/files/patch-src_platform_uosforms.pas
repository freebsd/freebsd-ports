--- src/platform/uosforms.pas.orig	2014-07-27 14:35:14 UTC
+++ src/platform/uosforms.pas
@@ -96,7 +96,7 @@ procedure ShowDriveContextMenu(Parent: T
 }
 function ShowOpenIconDialog(Owner: TCustomControl; var sFileName : String) : Boolean;
 
-{$IF DEFINED(LINUX)}
+{$IF DEFINED(UNIX) AND NOT DEFINED(DARWIN)}
 {en
    Show open with dialog
    @param(FileList List of files to open with)
@@ -121,7 +121,7 @@ uses
     {$ELSE}
     , MacOSAll
     {$ENDIF}
-    {$IFDEF LINUX}
+    {$IF NOT DEFINED(DARWIN)}
     , fOpenWith, uKde
     {$ENDIF}
   {$ENDIF};
@@ -547,7 +547,7 @@ begin
     FreeAndNil(opdDialog);
 end;
 
-{$IF DEFINED(LINUX)}
+{$IF DEFINED(UNIX) AND NOT DEFINED(DARWIN)}
 procedure ShowOpenWithDialog(const FileList: TStringList);
 begin
   if not (UseKde and uKde.ShowOpenWithDialog(FileList)) then begin
