--- src/dmhelpmanager.pas.orig	2016-01-13 13:34:47 UTC
+++ src/dmhelpmanager.pas
@@ -106,12 +106,12 @@ begin
   else
     begin
       gHelpLang:= ExtractDelimited(2, gPOFileName, ['.']);
-      if not mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
+      if not mbDirectoryExists(gpDocsDir + PathDelim + gHelpLang) then
         gHelpLang:= 'en';
     end;
 
-  if mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
-    HTMLHelpDatabase.BaseURL:= 'file://' + gpExePath + 'doc' + PathDelim + gHelpLang
+  if mbDirectoryExists(gpDocsDir + PathDelim + gHelpLang) then
+    HTMLHelpDatabase.BaseURL:= 'file://' + gpDocsDir + PathDelim + gHelpLang
   else begin
     HTMLHelpDatabase.BaseURL:= 'http://doublecmd.github.io/doc/' + gHelpLang;
   end;
