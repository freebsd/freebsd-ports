--- ./src/dmhelpmanager.pas.orig	2013-06-30 19:27:17.154825000 +0200
+++ ./src/dmhelpmanager.pas	2013-06-30 19:28:32.591981000 +0200
@@ -69,11 +69,11 @@
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
