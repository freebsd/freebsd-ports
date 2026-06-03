-- Include FreeBSD in the shared defaultInterfaceMonitor implementation.
-- The shared code uses AF_ROUTE sockets and golang.org/x/net/route which
-- work identically on FreeBSD and Darwin.
--- vendor/github.com/sagernet/sing-tun/monitor_shared.go.orig	2026-05-04 16:34:14 UTC
+++ vendor/github.com/sagernet/sing-tun/monitor_shared.go
@@ -1,4 +1,4 @@
-//go:build linux || windows || darwin
+//go:build linux || windows || darwin || freebsd
 
 package tun
 
