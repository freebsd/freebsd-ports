--- src/cmds/restic/cmd_autocomplete.go.orig	2017-07-27 13:03:30 UTC
+++ src/cmds/restic/cmd_autocomplete.go
@@ -30,7 +30,7 @@ $ sudo restic autocomplete`,
 func init() {
 	cmdRoot.AddCommand(cmdAutocomplete)
 
-	cmdAutocomplete.Flags().StringVarP(&autocompleteTarget, "completionfile", "", "/etc/bash_completion.d/restic.sh", "autocompletion file")
+	cmdAutocomplete.Flags().StringVarP(&autocompleteTarget, "completionfile", "", "%%PREFIX%%/etc/bash_completion.d/restic.sh", "autocompletion file")
 	// For bash-completion
 	cmdAutocomplete.Flags().SetAnnotation("completionfile", cobra.BashCompFilenameExt, []string{})
 }
