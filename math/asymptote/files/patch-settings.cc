--- settings.cc.orig	2019-10-03 16:43:08 UTC
+++ settings.cc
@@ -99,7 +99,7 @@ string defaultPDFViewer="open";
 string defaultHTMLViewer="open";
 #else  
 string defaultPSViewer="gv";
-string defaultPDFViewer="acroread";
+string defaultPDFViewer="gv";
 string defaultHTMLViewer="google-chrome";
 #endif  
 string defaultGhostscript="gs";
