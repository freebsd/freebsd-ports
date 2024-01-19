--- winff/unit1.pas.orig	2023-10-01 15:40:03 UTC
+++ winff/unit1.pas
@@ -27,9 +27,9 @@ uses
   {$IFDEF WINDOWS} windows, shellapi, dos,{$endif}
   {$IFDEF unix} baseunix, unix, {$endif}
   laz_xmlcfg, dom, xmlread, xmlwrite, StdCtrls, Buttons, ActnList, Menus, unit2, unit3,
-  unit4, unit5, gettext, translations, process
+  unit4, unit5, gettext, translations, process, LazFileUtils, LazUTF8
   {$IFDEF TRANSLATESTRING}, DefaultTranslator{$ENDIF}, ExtCtrls, ComCtrls, Spin, UTF8Process,
-  PoTranslator, types, FileUtil, regexpr, LazUTF8, LazFileUtils;
+  PoTranslator, types, FileUtil, regexpr {$IFDEF WINDOWS}, LazUTF8, LazFileUtils{$endif} {$IFDEF linux}, LazUTF8, LazFileUtils{$endif};
 
 type
 
@@ -1241,13 +1241,13 @@ procedure TfrmMain.launchbrowser(URL:string);
 
 // launch browser
 procedure TfrmMain.launchbrowser(URL:string);
-{$IFDEF linux}
+{$IFDEF unix}
 var
 launcher:tprocess;
 s:string;
 {$endif}
 begin
-  {$ifdef linux}
+  {$ifdef unix}
   s:='';
   if fileexists('/usr/bin/konqueror') then s:='/usr/bin/konqueror';
   if fileexists('/usr/bin/mozilla-firefox') then s:='/usr/bin/mozilla-firefox';
@@ -1382,13 +1382,13 @@ procedure TfrmMain.LaunchPdf(pdffile:string);
 
 // launch pdf
 procedure TfrmMain.LaunchPdf(pdffile:string);
-{$IFDEF linux}
+{$IFDEF unix}
 var
 launcher:tprocess;
 s:string;
 {$endif}
 begin
-  {$ifdef linux}
+  {$ifdef unix}
   s:='';
   if fileexists('/usr/bin/okular') then s:='/usr/bin/okular';
   if fileexists('/usr/bin/evince') then s:='/usr/bin/evince';
@@ -1984,7 +1984,7 @@ begin
 language: string;
 begin
   language:=leftstr(lang,2);
-  {$ifdef linux}
+  {$ifdef unix}
   s :='';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf.gz') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf.gz';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf';
