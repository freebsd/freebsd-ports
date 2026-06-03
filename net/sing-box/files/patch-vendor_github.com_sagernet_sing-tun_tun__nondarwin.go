-- Exclude FreeBSD from the !darwin PacketOffset=0 fallback.
-- FreeBSD uses TUNSIFHEAD multi-AF mode, which requires PacketOffset=4
-- (same as Darwin).  FreeBSD gets its own PacketOffset constant in
-- tun_freebsd.go.
--- vendor/github.com/sagernet/sing-tun/tun_nondarwin.go.orig	2026-05-04 16:16:29 UTC
+++ vendor/github.com/sagernet/sing-tun/tun_nondarwin.go
@@ -1,4 +1,4 @@
-//go:build !darwin
+//go:build !darwin && !freebsd
 
 package tun
 
