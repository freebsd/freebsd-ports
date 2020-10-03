--- plugin_0_choria_provision.go.orig	2020-09-30 01:19:24 UTC
+++ plugin_0_choria_provision.go
@@ -0,0 +1,14 @@
+// auto generated 2020-09-28 11:42:32.813446154 -1000 -10 m=+0.007024270
+package main
+
+import (
+	"github.com/choria-io/go-choria/plugin"
+	p "github.com/choria-io/provisioning-agent/agent"
+)
+
+func init() {
+	err := plugin.Register("choria_provision", p.ChoriaPlugin())
+	if err != nil {
+		panic(err)
+	}
+}
