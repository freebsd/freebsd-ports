--- shell/completion.bash.orig	2020-05-25 18:52:57 UTC
+++ shell/completion.bash
@@ -252,7 +252,7 @@ _fzf_complete_kill() {
   [ -n "${COMP_WORDS[COMP_CWORD]}" ] && return 1
 
   local selected
-  selected=$(command ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS $FZF_COMPLETION_OPTS --preview 'echo {}' --preview-window down:3:wrap" __fzf_comprun "kill" -m | awk '{print $2}' | tr '\n' ' ')
+  selected=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS $FZF_COMPLETION_OPTS --preview 'echo {}' --preview-window down:3:wrap" __fzf_comprun "kill" -m | awk '{print $2}' | tr '\n' ' ')
   selected=${selected% }
   printf '\e[5n'
 
