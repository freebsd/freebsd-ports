--- winff/unit1.pas.orig	2013-08-16 03:55:46 UTC
+++ winff/unit1.pas
@@ -1228,13 +1228,13 @@ end;
 
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
@@ -1369,13 +1369,13 @@ end;
 
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
@@ -1953,7 +1953,7 @@ var s : string;
 language: string;
 begin
   language:=leftstr(lang,2);
-  {$ifdef linux}
+  {$ifdef unix}
   s :='';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf.gz') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf.gz';
   if fileexists('/usr/share/doc/winff/WinFF.' + language + '.pdf') then s:='/usr/share/doc/winff/WinFF.' + language + '.pdf';
