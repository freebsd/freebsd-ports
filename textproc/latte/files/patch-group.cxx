--- group.cxx.orig	Fri Oct 22 13:01:48 1999
+++ group.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_Group::Latte_Group(const Latte_Wstate &ws,
 			 const Latte_FileLoc &loc) :
   Latte_Tangible(ws, loc),
