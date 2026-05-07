--- pkg/envoy/extract_embed.go.orig	2026-04-08 18:24:26 UTC
+++ pkg/envoy/extract_embed.go
@@ -1,4 +1,4 @@
-//go:build !debug_local_envoy
+//go:build !debug_local_envoy && !freebsd
 
 package envoy
 
