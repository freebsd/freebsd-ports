--- ./classes/src/ArtsIfIndexSelectionSet.lex.orig	Mon Oct  2 13:05:24 2000
+++ ./classes/src/ArtsIfIndexSelectionSet.lex	Wed Sep 25 16:38:10 2002
@@ -48,6 +48,7 @@
 }
 
 #include <string>
+using namespace std;
 
 #ifdef HAVE_STRSTREAM
   #include <strstream>
