-- Exclude FreeBSD from the stub since it does not use DNS control.
--- core/server/internal/sys/set_dns_stub.go.orig	2026-05-05 00:00:00 UTC
+++ core/server/internal/sys/set_dns_stub.go
@@ -1,4 +1,4 @@
-//go:build !darwin
+//go:build !darwin && !freebsd
 
 package sys
 
