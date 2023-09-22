--- shell/completion.zsh.orig	2023-07-31 17:25:48.004185000 +0200
+++ shell/completion.zsh	2023-07-31 17:34:23.011756000 +0200
@@ -252,7 +252,7 @@
 
 _fzf_complete_kill() {
   _fzf_complete -m --header-lines=1 --preview 'echo {}' --preview-window down:3:wrap --min-height 15 -- "$@" < <(
-    command ps -eo user,pid,ppid,start,time,command 2> /dev/null ||
+    command ps -uef 2> /dev/null ||
       command ps -eo user,pid,ppid,time,args # For BusyBox
   )
 }
