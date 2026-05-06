--- /dev/null   2026-05-06 21:47:11.530097000 +0800
+++ cli/config/credentials/default_store_freebsd.go     2026-05-06 21:47:00.912081000 +0800
@@ -0,0 +1,13 @@
+package credentials
+
+import (
+       "os/exec"
+)
+
+func defaultCredentialsStore() string {
+       if _, err := exec.LookPath("pass"); err == nil {
+               return "pass"
+       }
+
+       return "secretservice"
+}
