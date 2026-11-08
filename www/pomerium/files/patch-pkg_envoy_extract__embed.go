--- pkg/envoy/extract_embed.go.orig	2026-07-26 03:56:20 UTC
+++ pkg/envoy/extract_embed.go
@@ -1,4 +1,4 @@
-//go:build !debug_local_envoy
+//go:build !debug_local_envoy && !freebsd

 package envoy

