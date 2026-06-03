-- Exclude FreeBSD from the stub that returns os.ErrInvalid.
-- FreeBSD now has a real TUN implementation in tun_freebsd.go.
--- vendor/github.com/sagernet/sing-tun/tun_other.go.orig	2026-05-04 16:34:14 UTC
+++ vendor/github.com/sagernet/sing-tun/tun_other.go
@@ -1,4 +1,4 @@
-//go:build !(linux || windows || darwin)
+//go:build !(linux || windows || darwin || freebsd)
 
 package tun
 
