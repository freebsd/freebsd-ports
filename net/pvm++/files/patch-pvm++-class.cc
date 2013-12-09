--- pvm++/class.cc.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/class.cc	2013-11-16 20:02:45.000000000 +0100
@@ -22,7 +22,7 @@
 
 namespace Pvm
 {
-  using namespace Internal;  
+  using namespace Internal_;  
 
   void
   Throw (int Error, const char *File, int Line)
