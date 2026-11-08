--- src/dmhelpmanager.pas.orig	2026-07-20 08:31:44 UTC
+++ src/dmhelpmanager.pas
@@ -104,7 +104,7 @@ var
 
   function CheckHelp(const HelpLang: String): Boolean;
   begin
-    Result:= mbDirectoryExists(gpExePath + 'doc' + PathDelim + HelpLang);
+    Result:= mbDirectoryExists(gpDocsDir + 'doc' + PathDelim + HelpLang);
     if not Result then Result:= ATranslations.IndexOf(HelpLang) >= 0;
   end;
 
@@ -116,7 +116,7 @@ begin
     try
       gHelpLang:= ExtractDelimited(2, gPOFileName, ['.']);
       try
-        ATranslations.LoadFromFile(gpExePath + 'doublecmd.help');
+        ATranslations.LoadFromFile(gpDocsDir + 'doublecmd.help');
       except
         // Ignore
       end;
@@ -134,8 +134,8 @@ begin
     end;
   end;
 
-  if mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
-    HTMLHelpDatabase.BaseURL:= 'file://' + gpExePath + 'doc' + PathDelim + gHelpLang
+  if mbDirectoryExists(gpDocsDir + 'doc' + PathDelim + gHelpLang) then
+    HTMLHelpDatabase.BaseURL:= 'file://' + gpDocsDir + 'doc' + PathDelim + gHelpLang
   else begin
     HTMLHelpDatabase.BaseURL:= 'https://doublecmd.github.io/doc/' + gHelpLang;
   end;
