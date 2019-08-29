--- vendor/github.com/mattn/go-ieproxy/proxyMiddleman_unix.go.orig	2019-08-27 16:11:57 UTC
+++ vendor/github.com/mattn/go-ieproxy/proxyMiddleman_unix.go
@@ -1,4 +1,4 @@
-//+build darwin unix linux
+//+build !windows
 
 package ieproxy
 
