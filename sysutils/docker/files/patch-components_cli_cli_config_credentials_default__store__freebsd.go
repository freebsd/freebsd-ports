--- components/cli/cli/config/credentials/default_store_freebsd.go.orig	2018-01-03 19:51:59 UTC
+++ components/cli/cli/config/credentials/default_store_freebsd.go
@@ -0,0 +1,13 @@
+package credentials
+
+import (
+	"github.com/docker/docker-credential-helpers/pass"
+)
+
+func defaultCredentialsStore() string {
+	if pass.PassInitialized {
+		return "pass"
+	}
+
+	return "secretservice"
+}
