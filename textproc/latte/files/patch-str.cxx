--- str.cxx.orig	Fri Oct 22 13:00:42 1999
+++ str.cxx	Fri Mar 19 01:17:52 2004
@@ -19,6 +19,8 @@
 #include <cstdio>
 #include <cstdlib>
 
+using namespace std;
+
 Latte_Str::Latte_Str(const Latte_Wstate &ws,
 		     const Latte_FileLoc &loc,
 		     const shstring &str) :
