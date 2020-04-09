--- helper/freeport/ephemeral_freebsd_test.go.orig	2020-04-09 18:14:37 UTC
+++ helper/freeport/ephemeral_freebsd_test.go
@@ -0,0 +1,18 @@
+//+build freebsd
+
+package freeport
+
+import (
+	"testing"
+)
+
+func TestGetEphemeralPortRange(t *testing.T) {
+	min, max, err := getEphemeralPortRange()
+	if err != nil {
+		t.Fatalf("err: %v", err)
+	}
+	if min <= 0 || max <= 0 || min > max {
+		t.Fatalf("unexpected values: min=%d, max=%d", min, max)
+	}
+	t.Logf("min=%d, max=%d", min, max)
+}
