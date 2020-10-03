--- plugin_4_scout.go.orig	2020-09-30 01:19:24 UTC
+++ plugin_4_scout.go
@@ -0,0 +1,14 @@
+// auto generated 2020-09-28 11:42:35.811480582 -1000 -10 m=+3.005058727
+package main
+
+import (
+	"github.com/choria-io/go-choria/plugin"
+	p "github.com/choria-io/go-choria/scout/agent/scout"
+)
+
+func init() {
+	err := plugin.Register("scout", p.ChoriaPlugin())
+	if err != nil {
+		panic(err)
+	}
+}
