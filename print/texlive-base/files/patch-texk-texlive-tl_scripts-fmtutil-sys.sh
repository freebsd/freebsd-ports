--- texk/texlive/tl_scripts/fmtutil-sys.sh.orig	2013-05-07 13:20:06.000000000 +0900
+++ texk/texlive/tl_scripts/fmtutil-sys.sh	2013-05-07 13:20:52.000000000 +0900
@@ -26,4 +26,4 @@
 TEXMFCONFIG="$c"
 export TEXMFVAR TEXMFCONFIG
 
-exec fmtutil ${1+"$@"}
+exec %%PREFIX%%/bin/fmtutil ${1+"$@"}
