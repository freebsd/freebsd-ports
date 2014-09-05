--- texk/texlive/tl_scripts/updmap-sys.sh.orig	2013-05-07 13:25:38.000000000 +0900
+++ texk/texlive/tl_scripts/updmap-sys.sh	2013-05-07 13:25:50.000000000 +0900
@@ -27,4 +27,4 @@
 TEXMFCONFIG="$c"
 export TEXMFVAR TEXMFCONFIG
 
-exec updmap ${1+"$@"}
+exec %%PREFIX%%/bin/updmap ${1+"$@"}
