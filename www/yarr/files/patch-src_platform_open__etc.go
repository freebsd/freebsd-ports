--- src/platform/open_etc.go.orig	2025-03-26 14:42:39 UTC
+++ src/platform/open_etc.go
@@ -1,4 +1,4 @@
-//go:build linux
+//go:build linux || freebsd
 
 package platform
 
