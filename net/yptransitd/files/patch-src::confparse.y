--- src/confparse.y.orig	Thu Aug 28 04:35:49 2003
+++ src/confparse.y	Thu Aug 28 04:35:56 2003
@@ -88,3 +88,4 @@
 ;
 modules_line: MODULES STRING_TOKEN { prefs.yp_modulelist = yp_modulelist_create($2); yylinecount++;
 					free($2); }
+;
