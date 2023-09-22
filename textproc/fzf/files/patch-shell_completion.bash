--- shell/completion.bash.orig	2023-07-31 17:35:49.551906000 +0200
+++ shell/completion.bash	2023-07-31 17:35:58.560554000 +0200
@@ -271,7 +271,7 @@
 
 _fzf_proc_completion() {
   _fzf_complete -m --header-lines=1 --preview 'echo {}' --preview-window down:3:wrap --min-height 15 -- "$@" < <(
-    command ps -eo user,pid,ppid,start,time,command 2> /dev/null ||
+    command ps -uef 2> /dev/null ||
       command ps -eo user,pid,ppid,time,args # For BusyBox
   )
 }
