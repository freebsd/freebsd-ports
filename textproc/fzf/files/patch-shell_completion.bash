--- shell/completion.bash.orig	2017-12-03 14:55:24 UTC
+++ shell/completion.bash
@@ -219,7 +219,8 @@ _fzf_complete_kill() {
 
   local selected fzf
   fzf="$(__fzfcmd_complete)"
-  selected=$(command ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" $fzf -m | awk '{print $2}' | tr '\n' ' ')
+  selected=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAU
+LT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" $fzf -m | awk '{print $2}' | tr '\n' ' ')
   printf '\e[5n'
 
   if [ -n "$selected" ]; then
