--- texk/texlive/tl_scripts/texconfig-sys.sh.orig	2013-05-07 13:24:39.000000000 +0900
+++ texk/texlive/tl_scripts/texconfig-sys.sh	2013-05-07 13:24:50.000000000 +0900
@@ -28,4 +28,4 @@
 TEXMFCONFIG="$c"
 export TEXMFVAR TEXMFCONFIG
 
-exec texconfig ${1+"$@"}
+exec %%PREFIX%%/bin/texconfig ${1+"$@"}
