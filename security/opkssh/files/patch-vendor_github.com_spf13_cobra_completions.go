--- vendor/github.com/spf13/cobra/completions.go.orig	2026-09-25 23:41:01 UTC
+++ vendor/github.com/spf13/cobra/completions.go
@@ -799,11 +799,11 @@ To load completions for every new session, execute onc
 
 #### Linux:
 
-	%[1]s completion bash > /etc/bash_completion.d/%[1]s
+	%[1]s completion bash > %%PREFIX%%/etc/bash_completion.d/%[1]s
 
 #### macOS:
 
-	%[1]s completion bash > $(brew --prefix)/etc/bash_completion.d/%[1]s
+	%[1]s completion bash > $(brew --prefix)%%PREFIX%%/etc/bash_completion.d/%[1]s
 
 You will need to start a new shell for this setup to take effect.
 `, c.Root().Name()),
