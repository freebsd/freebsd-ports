--- shell/completion.zsh.orig	2017-12-03 14:55:24.000000000 +0000
+++ shell/completion.zsh	2017-12-29 20:54:22.283164000 +0000
@@ -163,7 +163,9 @@
   # Kill completion (do not require trigger sequence)
   if [ $cmd = kill -a ${LBUFFER[-1]} = ' ' ]; then
     fzf="$(__fzfcmd_complete)"
-    matches=$(command ps -ef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFAULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" ${=fzf} -m | awk '{print $2}' | tr '\n' ' ')
+    matches=$(ps -uef | sed 1d | FZF_DEFAULT_OPTS="--height ${FZF_TMUX_HEIGHT:-50%} --min-height 15 --reverse $FZF_DEFA
+ULT_OPTS --preview 'echo {}' --preview-window down:3:wrap $FZF_COMPLETION_OPTS" ${=fzf} -m | awk '{print $2}' | tr '\n'
+' ')
     if [ -n "$matches" ]; then
       LBUFFER="$LBUFFER$matches"
     fi
