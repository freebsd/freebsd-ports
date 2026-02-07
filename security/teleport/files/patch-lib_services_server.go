--- lib/services/server.go.orig	2022-02-23 04:58:43 UTC
+++ lib/services/server.go
@@ -578,7 +578,7 @@ type CommandLabelV1 struct {
 	// Period is a time between command runs
 	Period time.Duration `json:"period"`
 	// Command is a command to run
-	Command []string `json:"command"` //["/usr/bin/hostname", "--long"]
+	Command []string `json:"command"` //["/bin/hostname", "--long"]
 	// Result captures standard output
 	Result string `json:"result"`
 }
