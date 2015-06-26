--- src/github.com/hashicorp/vault/helper/password/password_unix.go.orig	2015-05-11 18:30:01 UTC
+++ src/github.com/hashicorp/vault/helper/password/password_unix.go
@@ -1,4 +1,4 @@
-// +build linux darwin
+// +build linux darwin freebsd
 
 package password
 
