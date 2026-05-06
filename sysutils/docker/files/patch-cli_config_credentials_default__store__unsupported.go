--- cli/config/credentials/default_store_unsupported.go.orig	2026-05-06 21:53:08.203888000 +0800
+++ cli/config/credentials/default_store_unsupported.go	2026-05-06 21:53:28.419333000 +0800
@@ -1,4 +1,4 @@
-//go:build !windows && !darwin && !linux
+//go:build !windows && !darwin && !linux && !freebsd
 
 package credentials
 
