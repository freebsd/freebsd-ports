--- sig.cpp	Thu Aug 12 14:49:29 2004
+++ socket++/sig.cpp	Thu Aug 12 16:42:32 2004
@@ -21,7 +21,7 @@
 siginit siginit::init;
 sig& sig::nal = *siginit::init.s;
 
-typedef void (*sighnd_type) (...);
+typedef void (*sighnd_type) (int);
 
 extern "C" {
   static void sighandler (int signo) {
