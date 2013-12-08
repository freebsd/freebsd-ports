--- pvm++/host.cc.orig	2013-11-16 19:59:44.000000000 +0100
+++ pvm++/host.cc	2013-11-16 20:02:50.000000000 +0100
@@ -21,7 +21,7 @@
 
 namespace Pvm
 {
-  using namespace Internal;
+  using namespace Internal_;
 
   Host::operator unsigned int () const
   {
