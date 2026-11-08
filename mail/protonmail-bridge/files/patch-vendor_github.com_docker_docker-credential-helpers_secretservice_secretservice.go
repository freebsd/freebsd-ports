--- vendor/github.com/docker/docker-credential-helpers/secretservice/secretservice.go.orig	2026-07-26 08:24:06 UTC
+++ vendor/github.com/docker/docker-credential-helpers/secretservice/secretservice.go
@@ -1,4 +1,4 @@
-//go:build linux && cgo
+//go:build linux || freebsd && cgo
 
 package secretservice
 
