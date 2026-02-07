--- components/cli/cli/config/credentials/default_store_unsupported.go.orig	2017-12-27 17:03:35 UTC
+++ components/cli/cli/config/credentials/default_store_unsupported.go
@@ -1,4 +1,4 @@
-// +build !windows,!darwin,!linux
+// +build !windows,!darwin,!linux,!freebsd
 
 package credentials
 
