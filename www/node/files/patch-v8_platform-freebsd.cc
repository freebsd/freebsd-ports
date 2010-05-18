--- deps/v8/src/platform-freebsd.cc.orig	2010-05-18 11:11:48.000000000 +0800
+++ deps/v8/src/platform-freebsd.cc	2010-05-18 11:12:00.000000000 +0800
@@ -290,7 +290,7 @@ int OS::StackWalk(Vector<OS::StackFrame>
 
   int frames_count = backtrace(addresses.start(), frames_size);
 
-  char** symbols = backtrace_symbols(addresses, frames_count);
+  char** symbols = backtrace_symbols(addresses.start(), frames_count);
   if (symbols == NULL) {
     return kStackWalkError;
   }
