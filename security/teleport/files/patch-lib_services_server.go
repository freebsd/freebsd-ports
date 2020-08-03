--- lib/services/server.go.orig	2020-07-08 18:08:40 UTC
+++ lib/services/server.go
@@ -546,7 +546,7 @@ type CommandLabelV1 struct {
 	// Period is a time between command runs
 	Period time.Duration `json:"period"`
 	// Command is a command to run
-	Command []string `json:"command"` //["/usr/bin/hostname", "--long"]
+	Command []string `json:"command"` //["/bin/hostname", "--long"]
 	// Result captures standard output
 	Result string `json:"result"`
 }
