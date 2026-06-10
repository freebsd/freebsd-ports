--- auxil/spicy/hilti/runtime/include/configuration.h.orig	2026-05-12 18:14:47 UTC
+++ auxil/spicy/hilti/runtime/include/configuration.h
@@ -76,7 +76,7 @@ inline const Configuration& unsafeGet() {
  * matters.
  */
 inline const Configuration& unsafeGet() {
-    assert(detail::__configuration);
+    assert(detail::__configuration.get());
     return *detail::__configuration;
 }
 
