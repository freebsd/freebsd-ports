--- src/3rdparty/chromium/base/ranges/algorithm.h.orig	2023-11-09 11:32:20 UTC
+++ src/3rdparty/chromium/base/ranges/algorithm.h
@@ -60,9 +60,9 @@ class BinaryPredicateProjector {
 
  private:
   template <typename ProjT, typename ProjU, typename T, typename U>
-  using InvokeResult = invoke_result_t<Pred&,
-                                       invoke_result_t<ProjT&, T&&>,
-                                       invoke_result_t<ProjU&, U&&>>;
+  using InvokeResult = std::invoke_result_t<Pred&,
+                                       std::invoke_result_t<ProjT&, T&&>,
+                                       std::invoke_result_t<ProjU&, U&&>>;
 
   template <typename T, typename U, typename = InvokeResult<Proj1, Proj2, T, U>>
   constexpr std::pair<Proj1&, Proj2&> GetProjs(priority_tag<3>) const {
