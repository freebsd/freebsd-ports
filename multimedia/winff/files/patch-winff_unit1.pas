--- winff/unit1.pas.orig	2024-02-19 13:49:13 UTC
+++ winff/unit1.pas
@@ -31,7 +31,7 @@ uses
   {$IFDEF TRANSLATESTRING}, DefaultTranslator{$ENDIF},
   ExtCtrls, ComCtrls, Spin, UTF8Process, PoTranslator, types, FileUtil, regexpr
   {$IFDEF WINDOWS}, LazUTF8, LazFileUtils {$endif}
-  {$IFDEF linux},   LazUTF8, LazFileUtils {$endif};
+  {$IFDEF unix},   LazUTF8, LazFileUtils {$endif};
 
 type
 
