--- plugin_1_externalmco.go.orig	2020-09-30 01:19:24 UTC
+++ plugin_1_externalmco.go
@@ -0,0 +1,14 @@
+// auto generated 2020-09-28 11:42:33.57430812 -1000 -10 m=+0.767886243
+package main
+
+import (
+	"github.com/choria-io/go-choria/plugin"
+	p "github.com/choria-io/go-choria/providers/agent/mcorpc/external"
+)
+
+func init() {
+	err := plugin.Register("externalmco", p.ChoriaPlugin())
+	if err != nil {
+		panic(err)
+	}
+}
