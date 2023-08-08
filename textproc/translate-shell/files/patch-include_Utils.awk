--- include/Utils.awk.orig	2020-10-15 13:53:06 UTC
+++ include/Utils.awk
@@ -233,6 +233,8 @@ function dumpX(text, group,    command, temp) {
 function base64(text,    command, temp) {
     if (detectProgram("uname", "-s", 1) == "Linux") # GNU base64 wraps lines by default
         command = "echo -n " parameterize(text) PIPE "base64 -w0"
+    if (detectProgram("gbase64", "--version")) # GNU base64 is sometimes available as gbase64
+        command = "echo -n " parameterize(text) PIPE "gbase64 -w0"
     else
         command = "echo -n " parameterize(text) PIPE "base64"
     command = "bash -c " parameterize(command, "\"")
