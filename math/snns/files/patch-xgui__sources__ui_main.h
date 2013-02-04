--- xgui/sources/ui_main.h.orig	2008-04-21 16:56:25.000000000 +0900
+++ xgui/sources/ui_main.h	2012-10-24 04:50:27.000000000 +0900
@@ -23,7 +23,7 @@
 #define _UI_MAIN_DEFINED_
 
 
-extern void main (int, char **);
+extern int main (int, char **);
 
 #ifndef MAXPATHLEN
 #define MAXPATHLEN  512
