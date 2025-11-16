--- commands/readhome.go.orig	2025-11-15 19:19:27 UTC
+++ commands/readhome.go
@@ -14,7 +14,7 @@
 //
 // SPDX-License-Identifier: Apache-2.0
 
-//go:build linux || darwin
+//go:build linux || darwin || freebsd
 
 package commands
 
