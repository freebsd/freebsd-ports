--- texk/texlive/linked_scripts/texlive/fmtutil-sys.sh.orig	2015-04-20 07:45:42 UTC
+++ texk/texlive/linked_scripts/texlive/fmtutil-sys.sh
@@ -22,4 +22,4 @@ PATH="$mydir:$PATH"; export PATH
 # hack around a bug in zsh:
 test -n "${ZSH_VERSION+set}" && alias -g '${1+"$@"}'='"$@"'
 
-exec fmtutil --sys ${1+"$@"}
+exec %%PREFIX%%/bin/fmtutil --sys ${1+"$@"}
