--- latte-string.cxx.orig	Thu Dec  3 07:54:01 1998
+++ latte-string.cxx	Fri Mar 19 01:17:52 2004
@@ -17,6 +17,8 @@
 
 #include <latte-string.h>
 
+using namespace std;
+
 #ifndef latte_use_intrinsic_string
 
 // I shouldn't need to define these, but some compilers are stupid
