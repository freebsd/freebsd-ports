--- winff/unit1.pas	2016-09-21 16:40:54.000000000 -0500
+++ winff/unit1.pas	2018-03-07 17:35:42.310241000 -0500
@@ -27,7 +27,7 @@
   {$IFDEF WINDOWS} windows, shellapi, dos,{$endif}
   {$IFDEF unix} baseunix, unix, {$endif}
   laz_xmlcfg, dom, xmlread, xmlwrite, StdCtrls, Buttons, ActnList, Menus, unit2, unit3,
-  unit4, unit5, gettext, translations, process
+  unit4, unit5, gettext, translations, process, LazFileUtils, LazUTF8
   {$IFDEF TRANSLATESTRING}, DefaultTranslator{$ENDIF}, ExtCtrls, ComCtrls, Spin, UTF8Process,
   PoTranslator, types, FileUtil, regexpr;
 
@@ -1241,13 +1241,13 @@
 
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
@@ -1382,13 +1382,13 @@
 
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
   if fileexists('/usr/bin/evince') then s:='/usr/bin/evince';
   if fileexists('/usr/bin/kpdf') then s:='/usr/bin/kpdf';
@@ -1982,7 +1982,7 @@
 language: string;
 begin
   language:=leftstr(lang,2);
-  {$ifdef linux}
+  {$ifdef unix}
   s :='';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf.gz') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf.gz';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf';
