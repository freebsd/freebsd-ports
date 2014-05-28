--- ./settings.cc.orig	2014-05-22 18:11:31.000000000 +0200
+++ ./settings.cc	2014-05-27 05:26:36.000000000 +0200
@@ -94,10 +94,10 @@
 #ifdef __APPLE__
 string defaultPDFViewer="open";
 #else  
-string defaultPDFViewer="acroread";
+string defaultPDFViewer="gv";
 #endif  
 string defaultGhostscript="gs";
-string defaultGhostscriptLibrary="/usr/lib/libgs.so";
+string defaultGhostscriptLibrary="/usr/local/lib/libgs.so";
 string defaultDisplay="display";
 string defaultAnimate="animate";
 void queryRegistry() {}
