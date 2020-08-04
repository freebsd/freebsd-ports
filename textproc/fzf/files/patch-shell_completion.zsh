--- shell/completion.zsh.orig	2020-08-03 09:46:30 UTC
+++ shell/completion.zsh
@@ -252,7 +252,7 @@ _fzf_complete_unalias() {
 
 _fzf_complete_kill() {
   _fzf_complete -m --preview 'echo {}' --preview-window down:3:wrap --min-height 15 -- "$@" < <(
-    command ps -ef | sed 1d
+    command ps -uef | sed 1d
   )
 }
 
