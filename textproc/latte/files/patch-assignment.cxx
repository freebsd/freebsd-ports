--- assignment.cxx.orig	Fri Oct 22 13:01:12 1999
+++ assignment.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_Assignment::Latte_Assignment(const Latte_Wstate &ws,
 			 const Latte_FileLoc &loc,
 			 const shstring &name) :
