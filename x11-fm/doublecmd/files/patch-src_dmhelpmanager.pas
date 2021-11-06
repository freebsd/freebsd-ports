--- src/dmhelpmanager.pas.orig	2021-10-17 08:37:18 UTC
+++ src/dmhelpmanager.pas
@@ -106,7 +106,7 @@ begin
     gHelpLang:= 'en'
   else begin
     gHelpLang:= ExtractDelimited(2, gPOFileName, ['.']);
-    if not mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
+    if not mbDirectoryExists(gpDocsDir + 'doc' + PathDelim + gHelpLang) then
     begin
       ATranslations:= TStringListEx.Create;
       try
@@ -119,8 +119,8 @@ begin
     end;
   end;
 
-  if mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
-    HTMLHelpDatabase.BaseURL:= 'file://' + gpExePath + 'doc' + PathDelim + gHelpLang
+  if mbDirectoryExists(gpDocsDir + 'doc' + PathDelim + gHelpLang) then
+    HTMLHelpDatabase.BaseURL:= 'file://' + gpDocsDir + 'doc' + PathDelim + gHelpLang
   else begin
     HTMLHelpDatabase.BaseURL:= 'https://doublecmd.github.io/doc/' + gHelpLang;
   end;
