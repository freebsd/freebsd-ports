--- src/dmhelpmanager.pas	2012-03-31 17:53:05.000000000 -0500
+++ src/dmhelpmanager.pas	2012-03-31 17:53:05.000000000 -0500
@@ -62,11 +62,11 @@
   else
     begin
       gHelpLang:= ExtractDelimited(2, gPOFileName, ['.']);
-      if not mbDirectoryExists(gpExePath + 'doc' + PathDelim + gHelpLang) then
+      if not mbDirectoryExists('/usr/local/share/doc/doublecmd' + PathDelim + gHelpLang) then
         gHelpLang:= 'en';
     end;
 
-  HTMLHelpDatabase.BaseURL:= 'file://' + gpExePath + 'doc' + PathDelim + gHelpLang;
+  HTMLHelpDatabase.BaseURL:= 'file:///usr/local/share/doc/doublecmd' + PathDelim + gHelpLang;
   HTMLHelpDatabase.KeywordPrefix:= '/';
 end;
 
