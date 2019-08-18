--- examples/te-benchmark/benchmark.cpp.orig	2017-08-16 16:07:38 UTC
+++ examples/te-benchmark/benchmark.cpp
@@ -23,6 +23,10 @@
 #include <boost/random/taus88.hpp>
 #include <boost/thread/tss.hpp>
 
+#ifndef WT_WIN32
+extern char **environ;
+#endif // WT_WIN32
+
 class MyMessage {
 public:
   std::string message;
