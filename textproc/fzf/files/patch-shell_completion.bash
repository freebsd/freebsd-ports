--- shell/completion.bash.orig	2020-08-03 09:46:24 UTC
+++ shell/completion.bash
@@ -262,7 +262,7 @@ _fzf_complete_kill() {
 
 _fzf_proc_completion() {
   _fzf_complete -m --preview 'echo {}' --preview-window down:3:wrap --min-height 15 -- "$@" < <(
-    command ps -ef | sed 1d
+    command ps -uef | sed 1d
   )
 }
 
