--- install.sh.orig	2021-09-22 16:18:31 UTC
+++ install.sh
@@ -403,13 +403,13 @@ theme_colors() {
         theme_color='indigo'
         ;;
     esac
-    sed -i "/\$color:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+    gsed -i "/\$color:/s/default/${theme_color}/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
   fi
 }
 
 bakground_image() {
     echo "Install with no nautilus bakground image..."
-    sed -i "/\$theme_image:/s/true/false/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
+    gsed -i "/\$theme_image:/s/true/false/" ${SRC_DIR}/src/_sass/_tweaks-temp.scss
 }
 
 theme_tweaks() {
