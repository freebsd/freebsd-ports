--- param.cxx.orig	Fri Oct 22 13:00:12 1999
+++ param.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 Latte_Param::Latte_Param(const Latte_Wstate &ws,
 			 const Latte_FileLoc &loc,
 			 const shstring &name,
