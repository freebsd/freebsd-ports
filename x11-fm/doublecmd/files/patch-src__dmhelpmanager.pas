--- src/dmhelpmanager.pas.orig	2015-08-17 15:35:25 UTC
+++ src/dmhelpmanager.pas
@@ -69,11 +69,11 @@ begin
   else
     begin
       gHelpLang:= ExtractDelimited(2, gPOFileName, ['.']);
-      if not mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
+      if not mbDirectoryExists(gpDocsDir + PathDelim + gHelpLang) then
         gHelpLang:= 'en';
     end;
 
-  HTMLHelpDatabase.BaseURL:= 'file://' + gpExePath + 'doc' + PathDelim + gHelpLang;
+  HTMLHelpDatabase.BaseURL:= 'file://' + gpDocsDir + PathDelim + gHelpLang;
   HTMLHelpDatabase.KeywordPrefix:= '/';
 
   {$IFDEF MSWindows}
