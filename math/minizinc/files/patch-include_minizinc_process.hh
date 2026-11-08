-- add environ declaration

--- include/minizinc/process.hh.orig	2026-09-17 20:29:15 UTC
+++ include/minizinc/process.hh
@@ -39,6 +39,8 @@
 #include <thread>
 #include <vector>
 
+extern char **environ;
+
 namespace MiniZinc {
 
 #if !defined(_WIN32) && !defined(__EMSCRIPTEN__)
