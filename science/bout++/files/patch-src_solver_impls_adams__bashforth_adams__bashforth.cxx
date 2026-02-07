--- src/solver/impls/adams_bashforth/adams_bashforth.cxx.orig	2022-12-23 20:47:59 UTC
+++ src/solver/impls/adams_bashforth/adams_bashforth.cxx
@@ -7,6 +7,8 @@
 
 #include <output.hxx>
 
+#include <array>
+
 namespace {
 BoutReal lagrange_at_position_denominator(const std::deque<BoutReal>& grid,
                                           const int position, const int order) {
