--- restranslator.pas	2019-08-15 13:06:50.472675000 -0500
+++ restranslator.pas	2019-08-15 13:07:17.952867000 -0500
@@ -196,7 +196,7 @@
       if _IsLangDir(s) then
         FDefaultLangDir:=s
       else begin
-        s:='/usr/local/share/' + ExtractFileNameOnly(ParamStrUtf8(0)) + '/lang/';
+        s:='%%DATADIR%%/lang/';
         if _IsLangDir(s) then
           FDefaultLangDir:=s;
       end;
