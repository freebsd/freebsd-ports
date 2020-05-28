--- shell/completion.zsh.orig	2020-05-25 18:53:01 UTC
+++ shell/completion.zsh
@@ -276,7 +276,7 @@ fzf-completion() {
   tail=${LBUFFER:$(( ${#LBUFFER} - ${#trigger} ))}
   # Kill completion (do not require trigger sequence)
   if [ $cmd = kill -a ${LBUFFER[-1]} = ' ' ]; then
-    matches=$(command ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS $FZF_COMPLETION_OPTS --preview 'echo {}' --preview-window down:3:wrap" __fzf_comprun "$cmd" -m | awk '{print $2}' | tr '\n' ' ')
+    matches=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS $FZF_COMPLETION_OPTS --preview 'echo {}' --preview-window down:3:wrap" __fzf_comprun "$cmd" -m | awk '{print $2}' | tr '\n' ' ')
     if [ -n "$matches" ]; then
       LBUFFER="$LBUFFER$matches"
     fi
