--- wstate.cxx.orig	Thu Dec  3 07:54:01 1998
+++ wstate.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 unsigned int Latte_Wstate::tab_width = 8;
 
 Latte_Wstate::Latte_Wstate() :
