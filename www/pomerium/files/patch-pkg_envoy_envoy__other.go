--- pkg/envoy/envoy_other.go.orig	2026-04-23 05:34:25 UTC
+++ pkg/envoy/envoy_other.go
@@ -1,5 +1,5 @@
-//go:build !linux && !darwin
-// +build !linux,!darwin
+//go:build !linux && !darwin && !freebsd
+// +build !linux,!darwin,!freebsd
 
 package envoy
 
