--- src/service/mod.rs.orig	2026-11-25 16:37:21 UTC
+++ src/service/mod.rs
@@ -1,3 +1,4 @@
+#![recursion_limit = "256"]
 #![expect(refining_impl_trait)]
 
 mod manager;
