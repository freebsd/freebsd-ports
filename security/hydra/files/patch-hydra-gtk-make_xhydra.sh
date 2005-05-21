--- hydra-gtk/make_xhydra.sh.orig	Fri May 20 17:03:45 2005
+++ hydra-gtk/make_xhydra.sh	Fri May 20 17:04:06 2005
@@ -8,7 +8,7 @@
   cat errors
   exit 1
 }
-make > /dev/null 2> errors
+gmake > /dev/null 2> errors
 test -e src/xhydra || {
   echo "Error: could not compile. Analyse this:"
   cat errors
