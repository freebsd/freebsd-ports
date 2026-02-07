--- hydra-gtk/make_xhydra.sh.orig	2020-07-29 07:36:37 UTC
+++ hydra-gtk/make_xhydra.sh
@@ -8,7 +8,7 @@ test -e Makefile || {
   cat errors
   exit 1
 }
-make > /dev/null 2> errors
+gmake > /dev/null 2> errors
 test -e src/xhydra || {
   echo "Error: could not compile. Analyse this:"
   cat errors
