--- boolean.cxx.orig	Fri Oct 22 13:01:24 1999
+++ boolean.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte.h>
 
+using namespace std;
+
 const Refcounter<Latte_Obj> &
 latte_false()
 {
