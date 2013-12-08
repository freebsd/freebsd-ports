--- pvm++/handlertabletype.cc.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/handlertabletype.cc	2013-11-16 20:03:09.000000000 +0100
@@ -21,7 +21,7 @@
 
 namespace Pvm
 {
-  using namespace Internal;
+  using namespace Internal_;
 
   ReceiveAction
   HandlerTableType::Install (Struct &Struct, ReceiveAction What)
