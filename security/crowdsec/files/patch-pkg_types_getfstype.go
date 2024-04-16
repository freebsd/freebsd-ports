--- pkg/types/getfstype.go.orig	2024-04-24 21:23:59 UTC
+++ pkg/types/getfstype.go
@@ -1,4 +1,4 @@
-//go:build !windows
+//go:build !windows && !freebsd
 
 package types
 
