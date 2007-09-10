--- lib/scripts/patch-scripts.bash.orig	Sun Sep  2 15:55:18 2007
+++ lib/scripts/patch-scripts.bash	Sun Sep  2 16:06:41 2007
@@ -3,12 +3,12 @@
 # Author: Markus Wenzel, TU Muenchen
 #
 # patch-scripts.bash - relocate interpreter paths of executable scripts and
-#   insert AUTO_BASH/AUTO_PERL values
+#   insert AUTO_PERL values
 #
 
 ## find binaries
 
-function findbin()
+findbin()
 {
   local BASE="$1"
   local BINARY=""
@@ -29,17 +29,14 @@
 
 ## main
 
-[ -z "$BASH_PATH" ] && BASH_PATH=$(findbin bash)
 [ -z "$PERL_PATH" ] && PERL_PATH=$(findbin perl)
-[ -z "$AUTO_BASH" ] && AUTO_BASH="$BASH_PATH"
 [ -z "$AUTO_PERL" ] && AUTO_PERL="$PERL_PATH"
 
 for FILE in $(find . -type f -print)
 do
   if [ -x "$FILE" ]; then
-    sed -e "s:^#!.*/bash:#!$BASH_PATH:" -e "s:^#!.*/perl:#!$PERL_PATH:" \
-      -e "s:^AUTO_BASH=.*bash:AUTO_BASH=$AUTO_BASH:" \
-      -e "s:^AUTO_PERL=.*perl:AUTO_PERL=$AUTO_PERL:" "$FILE" > "$FILE~~"
+    sed -e "s:^#!.*/perl:#!$PERL_PATH:" \
+        -e "s:^AUTO_PERL=.*perl:AUTO_PERL=$AUTO_PERL:" "$FILE" > "$FILE~~"
     if cmp -s "$FILE" "$FILE~~"; then
       rm "$FILE~~"
     else
