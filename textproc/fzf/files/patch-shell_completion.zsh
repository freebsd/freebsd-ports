--- shell/completion.zsh.orig	2017-12-03 14:55:24 UTC
+++ shell/completion.zsh
@@ -163,7 +163,7 @@ fzf-completion() {
   # Kill completion (do not require trigger sequence)
   if [ $cmd = kill -a ${LBUFFER[-1]} = ' ' ]; then
     fzf="$(__fzfcmd_complete)"
-    matches=$(command ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" ${=fzf} -m | awk '{print $2}' | tr '\n' ' ')
+    matches=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" ${=fzf} -m | awk '{print $2}' | tr '\n' ' ')
     if [ -n "$matches" ]; then
       LBUFFER="$LBUFFER$matches"
     fi
