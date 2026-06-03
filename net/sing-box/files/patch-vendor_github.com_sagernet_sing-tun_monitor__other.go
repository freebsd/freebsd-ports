-- Exclude FreeBSD from the stub monitor that returns os.ErrInvalid.
-- FreeBSD now has a real monitor implementation in monitor_freebsd.go.
--- vendor/github.com/sagernet/sing-tun/monitor_other.go.orig	2026-05-04 16:34:14 UTC
+++ vendor/github.com/sagernet/sing-tun/monitor_other.go
@@ -1,4 +1,4 @@
-//go:build !(linux || windows || darwin)
+//go:build !(linux || windows || darwin || freebsd)
 
 package tun
 
