--- auxil/spicy/spicy/runtime/include/configuration.h.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/spicy/runtime/include/configuration.h
@@ -43,7 +43,7 @@ inline const Configuration& unsafeGet() {
  * matters.
  */
 inline const Configuration& unsafeGet() {
-    assert(rt::detail::globalState()->configuration);
+    assert(rt::detail::globalState()->configuration.get());
     return *rt::detail::globalState()->configuration;
 }
 
