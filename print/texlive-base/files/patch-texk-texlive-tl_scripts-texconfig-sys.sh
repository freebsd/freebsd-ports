--- texk/texlive/tl_scripts/texconfig-sys.sh.orig	2014-07-13 00:06:11 UTC
+++ texk/texlive/tl_scripts/texconfig-sys.sh
@@ -30,4 +30,4 @@ TEXMFVAR="$v"
 TEXMFCONFIG="$c"
 export TEXMFVAR TEXMFCONFIG
 
-exec texconfig ${1+"$@"}
+exec %%PREFIX%%/bin/texconfig ${1+"$@"}
