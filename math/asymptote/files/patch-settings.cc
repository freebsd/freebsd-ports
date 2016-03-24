--- settings.cc.orig	2016-03-14 05:33:18 UTC
+++ settings.cc
@@ -95,7 +95,7 @@ string defaultPSViewer="gv";
 #ifdef __APPLE__
 string defaultPDFViewer="open";
 #else  
-string defaultPDFViewer="acroread";
+string defaultPDFViewer="gv";
 #endif  
 string defaultGhostscript="gs";
 string defaultGhostscriptLibrary="/usr/lib/libgs.so";
