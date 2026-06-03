-- Exclude FreeBSD from the generic monitor stub; a FreeBSD-specific stub is
-- provided separately.
--- core/server/internal/boxdns/monitor_stub.go.orig	2026-05-05 00:00:00 UTC
+++ core/server/internal/boxdns/monitor_stub.go
@@ -1,4 +1,4 @@
-//go:build !windows
+//go:build !windows && !freebsd
 
 package boxdns
 
