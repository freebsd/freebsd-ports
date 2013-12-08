--- pvm++/struct.cc.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/struct.cc	2013-11-16 20:03:01.000000000 +0100
@@ -21,7 +21,7 @@
 
 namespace Pvm
 {
-  using namespace Internal;
+  using namespace Internal_;
 
   Task Struct::IgnoreTask;
   bool Struct::CurrentlyPacking;
