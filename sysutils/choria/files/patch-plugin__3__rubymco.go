--- plugin_3_rubymco.go.orig	2020-09-30 01:19:24 UTC
+++ plugin_3_rubymco.go
@@ -0,0 +1,14 @@
+// auto generated 2020-09-28 11:42:35.067195884 -1000 -10 m=+2.260774017
+package main
+
+import (
+	"github.com/choria-io/go-choria/plugin"
+	p "github.com/choria-io/go-choria/providers/agent/mcorpc/ruby"
+)
+
+func init() {
+	err := plugin.Register("rubymco", p.ChoriaPlugin())
+	if err != nil {
+		panic(err)
+	}
+}
