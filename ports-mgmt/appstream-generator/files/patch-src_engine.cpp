--- src/engine.cpp.orig	2025-09-25 21:14:13 UTC
+++ src/engine.cpp
@@ -35,6 +35,7 @@
 
 #include <tbb/parallel_for.h>
 #include <tbb/parallel_for_each.h>
+#include <tbb/parallel_invoke.h>
 #include <tbb/blocked_range.h>
 #include <tbb/task_arena.h>
 #include <inja/inja.hpp>
