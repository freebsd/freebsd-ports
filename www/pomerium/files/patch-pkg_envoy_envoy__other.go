--- pkg/envoy/envoy_other.go.orig	2026-07-26 03:56:20 UTC
+++ pkg/envoy/envoy_other.go
@@ -1,4 +1,4 @@
-//go:build !linux && !darwin
+//go:build !linux && !darwin && !freebsd

 package envoy

