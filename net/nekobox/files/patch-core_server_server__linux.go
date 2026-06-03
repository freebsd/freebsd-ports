-- Add explicit linux build constraint so the file is not compiled on FreeBSD.
--- core/server/server_linux.go.orig	2026-05-05 00:00:00 UTC
+++ core/server/server_linux.go
@@ -1,3 +1,5 @@
+//go:build linux
+
 package main
 
 import (
