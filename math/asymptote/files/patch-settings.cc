--- settings.cc.orig	2024-10-07 18:22:37 UTC
+++ settings.cc
@@ -101,9 +101,9 @@ string defaultHTMLViewer="open";
 string defaultPDFViewer="open";
 string defaultHTMLViewer="open";
 #else
-string defaultPSViewer="evince";
-string defaultPDFViewer="evince";
-string defaultHTMLViewer="google-chrome";
+string defaultPSViewer="gv";
+string defaultPDFViewer="xdg-open";
+string defaultHTMLViewer="xdg-open";
 #endif
 string defaultGhostscript="gs";
 string defaultGhostscriptLibrary="";
