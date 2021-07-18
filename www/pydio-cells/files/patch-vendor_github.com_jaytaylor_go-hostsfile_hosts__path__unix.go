--- vendor/github.com/jaytaylor/go-hostsfile/hosts_path_unix.go.orig	2021-05-10 22:23:40 UTC
+++ vendor/github.com/jaytaylor/go-hostsfile/hosts_path_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build !plan9 !windows
 
 package hostsfile
 
