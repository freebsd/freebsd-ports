--- shell/completion.bash.orig	2017-10-25 13:15:42 UTC
+++ shell/completion.bash
@@ -215,7 +215,7 @@ _fzf_complete_kill() {
 
   local selected fzf
   fzf="$(__fzfcmd_complete)"
-  selected=$(ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" $fzf -m | awk '{print $2}' | tr '\n' ' ')
+  selected=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" $fzf -m | awk '{print $2}' | tr '\n' ' ')
   printf '\e[5n'
 
   if [ -n "$selected" ]; then
