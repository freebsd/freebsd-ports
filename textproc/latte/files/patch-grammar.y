--- grammar.y.orig	Fri Oct 22 12:47:11 1999
+++ grammar.y	Fri Mar 19 01:17:52 2004
@@ -24,6 +24,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 struct Tangible {
   Tangible(const Latte_Wstate &w, const Latte_FileLoc &l) : ws(w), loc(l) {}
 
