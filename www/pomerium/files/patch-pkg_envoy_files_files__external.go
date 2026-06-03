--- pkg/envoy/files/files_external.go.orig	2026-04-08 18:24:26 UTC
+++ pkg/envoy/files/files_external.go
@@ -1,4 +1,4 @@
-//go:build embed_pomerium || debug_local_envoy
+//go:build embed_pomerium || debug_local_envoy || freebsd
 
 package files
 
