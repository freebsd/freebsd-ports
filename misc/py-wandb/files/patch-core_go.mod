-- Keep the Go build offline in FreeBSD ports by avoiding auto toolchain download.
-- The go126 port currently provides Go 1.26.2, while upstream declares go 1.26.3.
-- In poudriere jails, downloading a newer toolchain from proxy.golang.org is blocked.

--- core/go.mod.orig	2026-05-16 00:00:00 UTC
+++ core/go.mod
@@ -1,6 +1,6 @@
 module github.com/wandb/wandb/core
 
-go 1.26.3
+go 1.26.2
 
 require (
 	charm.land/bubbles/v2 v2.1.0
